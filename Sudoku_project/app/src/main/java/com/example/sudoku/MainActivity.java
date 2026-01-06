package com.example.sudoku;

import android.content.Intent;
import android.os.Bundle;
import android.widget.Button;

import androidx.appcompat.app.AppCompatActivity;
import androidx.appcompat.app.AppCompatDelegate;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        AppCompatDelegate.setDefaultNightMode(AppCompatDelegate.MODE_NIGHT_YES); // всегда тёмная

        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        Button btnPlay = findViewById(R.id.buttonPlay);
        btnPlay.setOnClickListener(v -> {
            Intent intent = new Intent(MainActivity.this, DifficultyActivity.class);
            startActivity(intent);
        });

        Button btnInfo = findViewById(R.id.buttonInfo);
        btnInfo.setOnClickListener(v -> {
            Intent intent = new Intent(MainActivity.this, InfoActivity.class);
            startActivity(intent);
        });
    }
}
