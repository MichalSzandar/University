package me.michal.restapi.model;


import com.fasterxml.jackson.annotation.JsonBackReference;

import jakarta.persistence.*;
import lombok.*;

@Getter @Setter @NoArgsConstructor @AllArgsConstructor @Builder
@Entity
public class Review {
    @Id @GeneratedValue(strategy = GenerationType.IDENTITY)
    private Long id;

    private String content;

    @ManyToOne
    @JoinColumn(name = "user_id")
    @JsonBackReference(value = "user-reviews")
    private User user;

    @ManyToOne
    @JoinColumn(name = "product_id")
    @JsonBackReference(value = "product-reviews")
    private Product product;
}