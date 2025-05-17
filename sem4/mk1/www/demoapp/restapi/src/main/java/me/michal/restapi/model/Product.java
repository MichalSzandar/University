package me.michal.restapi.model;


import jakarta.persistence.*;
import lombok.*;

import java.util.Set;

@Getter @Setter @NoArgsConstructor @AllArgsConstructor @Builder
@Entity
public class Product {
    @Id @GeneratedValue(strategy = GenerationType.IDENTITY)
    private Long id;

    private String name;

    private String description;

    @OneToMany(mappedBy = "product")
    private Set<Review> reviews;
}