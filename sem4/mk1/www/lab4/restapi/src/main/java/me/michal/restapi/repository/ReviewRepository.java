package me.michal.restapi.repository;

import org.springframework.data.domain.Page;
import org.springframework.data.domain.Pageable;
import org.springframework.data.jpa.repository.JpaRepository;

import me.michal.restapi.model.Review;

public interface ReviewRepository extends JpaRepository<Review, Long> {
    Page<Review> findByUserId(Long userId, Pageable pageable);
    Page<Review> findByProductId(Long productId, Pageable pageable);
}