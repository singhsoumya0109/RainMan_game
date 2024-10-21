#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QKeyEvent>
#include <QRandomGenerator>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), score(0) {
    ui->setupUi(this);

    scene = new QGraphicsScene(this);
    scene->setSceneRect(0, 0, 800, 600);

    view = new QGraphicsView(scene, this);
    view->setFixedSize(800, 600);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setFocusPolicy(Qt::StrongFocus);
    setCentralWidget(view);
    view->setFocus(); // Set focus to the view

    // Create the umbrella
    umbrella = new Umbrella(350, 550, 130, 20,this);
    scene->addItem(umbrella);
    qDebug() << "Initial x position of umbrella:" << umbrella->x();


    scoreLabel = new QLabel(this);
    scoreLabel->setGeometry(650, 10, 150, 30); // Position at the top-right
    scoreLabel->setText("Score: 0");
    scoreLabel->setStyleSheet("QLabel { color : black; font-size: 18px; }");


    // Timers for raindrop spawning and game updates
    spawnTimer = new QTimer(this);
    connect(spawnTimer, &QTimer::timeout, this, &MainWindow::spawnRaindrop);
    spawnTimer->start(1000); // Spawn a raindrop every second

    gameTimer = new QTimer(this);
    connect(gameTimer, &QTimer::timeout, this, &MainWindow::updateGame);
    gameTimer->start(50); // Update game state every 50 ms
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::spawnRaindrop() {
    int x = QRandomGenerator::global()->bounded(0, 700); // Random x position for raindrop
    Raindrop *raindrop = new Raindrop(x, 0, 5, 20); // Create raindrop at random position
    raindrops.append(raindrop); // Add raindrop to list
    scene->addItem(raindrop); // Add raindrop to scene
}

void MainWindow::updateGame() {
    // Move raindrops down and check for collisions
    for (int i = 0; i < raindrops.size(); ++i) {
        Raindrop *raindrop = raindrops[i];
        raindrop->moveDown(5); // Move the raindrop down by 5 units

        // Check collision with umbrella
        if (raindrop->collidesWithItem(umbrella)) {
            scene->removeItem(raindrop);
            raindrops.removeAt(i);
            delete raindrop;
            --i;
            updateScore(1);
            // Update score here if needed

        } else if (raindrop->isOutOfScreen(scene->height())) {
            scene->removeItem(raindrop);
            raindrops.removeAt(i);
            delete raindrop;
            --i;
        }
    }
}

void MainWindow::keyPressEvent(QKeyEvent *event) {
    qDebug() << "Key Pressed:" << event->key(); // Debug print to show the key code
    int distance = 5; // Distance the umbrella moves

    // Move the umbrella left or right using "A" and "D" keys
    if (event->key() == Qt::Key_A) { // A for left
        umbrella->moveLeft(distance);
        qDebug() << "Moved left";
    } else if (event->key() == Qt::Key_D) { // D for right
        umbrella->moveRight(distance, scene->width());
        qDebug() << "Moved right";
    }

}
void MainWindow::updateScore(int points) {
    score += points;
    scoreLabel->setText("Score: " + QString::number(score));
}

// Set up the scene
// scene = new QGraphicsScene(this);
// scene->setSceneRect(0, 0, 800, 600);

// Set up the view

// if (event->key() == Qt::Key_Left) {
//     umbrella->moveLeft(distance);
//     qDebug() << "Moved left";
//     event->accept(); // Accept the event
// } else if (event->key() == Qt::Key_Right) {
//     umbrella->moveRight(distance, scene->width());
//     qDebug() << "Moved right";
//     event->accept(); // Accept the event
// } else {
//     event->ignore(); // Ignore other keys
// }
