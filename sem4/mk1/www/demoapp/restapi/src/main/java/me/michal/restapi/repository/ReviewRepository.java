package me.michal.restapi.repository;

import org.springframework.data.jpa.repository.JpaRepository;

import me.michal.restapi.model.Review;

public interface ReviewRepository extends JpaRepository<Review, Long> {
}