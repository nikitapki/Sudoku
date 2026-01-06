package com.example.sudoku;

import android.os.Bundle;
import android.widget.Button;

import androidx.appcompat.app.AppCompatActivity;

public class InfoActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_info);

        // Кнопка "Назад"
        Button btnBack = findViewById(R.id.btnBackToGame);
        btnBack.setOnClickListener(v -> finish()); // просто возвращаемся назад
    }
}
