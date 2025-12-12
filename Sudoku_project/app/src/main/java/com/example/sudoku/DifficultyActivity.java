package com.example.sudoku;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;

import androidx.appcompat.app.AppCompatActivity;
import com.example.sudoku.core.RandomLCG;

public class DifficultyActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_difficult);

        Button btnEasy = findViewById(R.id.buttonDifficultEasy);
        Button btnMedium = findViewById(R.id.buttonDifficultMedium);
        Button btnHard = findViewById(R.id.buttonDifficultHard);
        Button btnImpossible = findViewById(R.id.buttonDifficultImpossible);
        Button btnBack = findViewById(R.id.buttonDifficultReturnBack);

        View.OnClickListener difficultyListener = new View.OnClickListener() {
            @Override
            public void onClick(View v) {

                RandomLCG rand = new RandomLCG();

                int id = v.getId();

                if (id == R.id.buttonDifficultEasy) {
                    startGame(rand.random(21,30));
                } else if (id == R.id.buttonDifficultMedium) {
                    startGame(rand.random(31,40));
                } else if (id == R.id.buttonDifficultHard) {
                    startGame(rand.random(41,50));
                } else if (id == R.id.buttonDifficultImpossible) {
                    startGame(rand.random(51,60));
                } else if (id == R.id.buttonDifficultReturnBack) {
                    finish();
                }
            }
        };

        btnEasy.setOnClickListener(difficultyListener);
        btnMedium.setOnClickListener(difficultyListener);
        btnHard.setOnClickListener(difficultyListener);
        btnImpossible.setOnClickListener(difficultyListener);
        btnBack.setOnClickListener(difficultyListener);
    }

    private void startGame(int difficulty) {
        Intent intent = new Intent(DifficultyActivity.this, GameActivity.class);
        intent.putExtra("DIFFICULTY", difficulty);
        startActivity(intent);
        finish();
    }
}
