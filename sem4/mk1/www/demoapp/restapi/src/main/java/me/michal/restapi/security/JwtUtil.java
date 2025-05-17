package me.michal.restapi.security;

import io.jsonwebtoken.*;
import io.jsonwebtoken.security.Keys;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.stereotype.Component;

import javax.crypto.SecretKey;
import java.util.Date;

@Component
public class JwtUtil {

    @Value("${spring.security.jwt.secret}")
    private String jwtSecret;

    private static final long EXPIRATION_MS = 24 * 60 * 60 * 1000; // 1 day

    public String generateToken(String username, String role) {
        SecretKey key = Keys.hmacShaKeyFor(jwtSecret.getBytes());
        return Jwts.builder()
                .subject(username)
                .claim("role", role)
                .issuedAt(new Date())
                .expiration(new Date(System.currentTimeMillis() + EXPIRATION_MS))
                .signWith(key) // SignatureAlgorithm is inferred from the key
                .compact();
    }

    public String getUsername(String token) {
        return parseClaims(token).getPayload().getSubject();
    }

    public String getRole(String token) {
        return (String) parseClaims(token).getPayload().get("role");
    }

    public boolean validateToken(String token) {
        try {
            parseClaims(token);
            return true;
        } catch (JwtException | IllegalArgumentException e) {
            return false;
        }
    }

    private Jws<Claims> parseClaims(String token) {
        SecretKey key = Keys.hmacShaKeyFor(jwtSecret.getBytes());
        return Jwts.parser().verifyWith(key).build().parseSignedClaims(token);
    }
}