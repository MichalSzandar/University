package me.michal.restapi.controller;

import lombok.RequiredArgsConstructor;
import me.michal.restapi.model.User;
import me.michal.restapi.security.JwtUtil;
import me.michal.restapi.service.UserService;

import org.springframework.http.*;
import org.springframework.web.bind.annotation.*;

@RestController
@RequestMapping("/auth")
@RequiredArgsConstructor
public class AuthController {

    private final UserService userService;
    private final JwtUtil jwtUtil;

    @PostMapping("/register")
    public ResponseEntity<?> register(@RequestBody User user) {
        user.setRole("USER");
        var saved = userService.saveUser(user);
        return ResponseEntity.ok(saved);
    }

    @PostMapping("/login")
    public ResponseEntity<?> login(@RequestBody User user) {
        var u = userService.findByUsername(user.getUsername())
                .orElseThrow(() -> new RuntimeException("User not found"));
        if (!userService.loadUserByUsername(user.getUsername()).getPassword().equals(u.getPassword())) {
            return ResponseEntity.status(HttpStatus.UNAUTHORIZED).body("Invalid credentials");
        }
        String token = jwtUtil.generateToken(u.getUsername(), u.getRole());
        return ResponseEntity.ok(token);
    }
}