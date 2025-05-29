package me.michal.restapi.model;


import jakarta.persistence.*;
import lombok.*;

import java.util.Set;

import com.fasterxml.jackson.annotation.JsonBackReference;

@Getter @Setter @NoArgsConstructor @AllArgsConstructor @Builder
@Entity
public class Product {
    @Id @GeneratedValue(strategy = GenerationType.IDENTITY)
    private Long id;

    private String name;

    private String description;

    @OneToMany(mappedBy = "product")
    @JsonBackReference(value = "product-reviews")
    private Set<Review> reviews;
}