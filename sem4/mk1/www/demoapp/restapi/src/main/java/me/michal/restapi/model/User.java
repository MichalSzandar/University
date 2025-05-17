package me.michal.restapi.model;


import jakarta.persistence.*;
import lombok.*;

import java.util.Set;

@Getter @Setter @NoArgsConstructor @AllArgsConstructor @Builder
@Entity
@Table(name = "users")
public class User {
    @Id @GeneratedValue(strategy = GenerationType.IDENTITY)
    private Long id;

    @Column(unique = true, nullable = false)
    private String username;

    private String password;

    private String role; // "ADMIN" or "USER"

    @OneToMany(mappedBy = "user")
    private Set<Review> reviews;
}