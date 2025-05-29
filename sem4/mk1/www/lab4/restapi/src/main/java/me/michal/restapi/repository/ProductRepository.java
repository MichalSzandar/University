package me.michal.restapi.repository;

import org.springframework.data.jpa.repository.JpaRepository;

import me.michal.restapi.model.Product;

public interface ProductRepository extends JpaRepository<Product, Long> {
}