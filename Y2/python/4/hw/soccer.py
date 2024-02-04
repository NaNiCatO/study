import sys
from PySide6.QtCore import *
from PySide6.QtWidgets import *
from PySide6.QtGui import *
from PySide6.QtMultimedia import QSoundEffect

class Ball:
    def __init__(self):
        self.image = QPixmap("images/ball.png")
        self.x = 0
        self.y = 250
        self.w = 40
        self.h = 40
        self.shoot = False
        self.moving_left = False

    def draw(self, p):
        p.drawPixmap(QRect(self.x, self.y, self.w, self.h), self.image)

    def moving_x(self):
        if self.shoot:
            self.y -= 5
            if self.y < 0:
                self.shoot = False
                self.y = 250
        elif self.moving_left:
            self.x -= 5
        else:
            self.x += 5
    
    def is_hit(self, x, y, w, h):
        return x <= self.x <= x + w and y <= self.y <= y + (h/2)


class Goalkeeper:
    def __init__(self):
        self.image = QPixmap("images/goalkeeper.png")
        self.x = 0
        self.y = 60
        self.w = 40
        self.h = 40
        self.moving_left = False

    def draw(self, p):
        p.drawPixmap(QRect(self.x, self.y, self.w, self.h), self.image)

    def moving_x(self):
        if self.moving_left:
            self.x -= 3
        else:
            self.x += 3

class Goal:
    def __init__(self):
        self.image = QPixmap("images/goal.png")
        self.x = 0
        self.y = 10
        self.w = 300
        self.h = 100

    def draw(self, p):
        p.drawPixmap(QRect(self.x, self.y, self.w, self.h), self.image)

class Animation_area(QWidget):
    def __init__(self):
        QWidget.__init__(self, None)
        self.setMinimumSize(300, 300)
        self.score = 0
        self.arena_w = 300
        self.arena_h = 300
        self.ball = Ball()
        self.goalkeeper = Goalkeeper()
        self.goal = Goal()
        self.timer = QTimer(self)
        self.timer.timeout.connect(self.update_value)
        self.timer.start(20)
        self.QS_scored = QSoundEffect()
        self.QS_scored.setSource(QUrl.fromLocalFile("sounds/scored.wav"))
        self.QS_block = QSoundEffect()
        self.QS_block.setSource(QUrl.fromLocalFile("sounds/block.wav"))

    def ball_hit_goalkeeper(self):
        if self.ball.is_hit(self.goalkeeper.x, self.goalkeeper.y, self.goalkeeper.w, self.goalkeeper.h):
            self.QS_block.play()
            self.ball.shoot = False
            self.ball.y = 250
            print("Block")
        elif self.ball.is_hit(self.goal.x, self.goal.y, self.goal.w-50, self.goal.h):
            self.QS_scored.play()
            self.ball.shoot = False
            self.ball.y = 250
            print("Scored")
            self.score += 1

    def paintEvent(self, e):
        p = QPainter()
        p.begin(self)
        self.ball.draw(p)
        self.goalkeeper.draw(p)
        self.goal.draw(p)
        p.end()

    def update_value(self):
        self.ball_hit_goalkeeper()

        if self.ball.x > self.arena_w - self.ball.w:
            self.ball.moving_left = True
        elif self.ball.x < 0:
            self.ball.moving_left = False

        if self.goalkeeper.x > self.arena_w - self.goalkeeper.w:
            self.goalkeeper.moving_left = True
        elif self.goalkeeper.x < 0:
            self.goalkeeper.moving_left = False

        self.update()
        self.ball.moving_x()
        self.goalkeeper.moving_x()
        self.update()


class Simple_animation_window(QWidget):
    def __init__(self):
        QWidget.__init__(self, None)
        self.QS_shot = QSoundEffect()
        self.QS_shot.setSource(QUrl.fromLocalFile("sounds/kick.wav"))
        self.anim_area = Animation_area()
        layout = QVBoxLayout()
        self.score = self.anim_area.score
        self.score_label = QLabel("Score: " + str(self.score))
        layout.addWidget(self.score_label)
        layout.addWidget(self.anim_area)
        self.shoot_button = QPushButton("Shoot", self)
        self.shoot_button.clicked.connect(self.shoot_button_clicked)
        layout.addWidget(self.shoot_button)
        self.setLayout(layout)
        self.setMinimumSize(330, 400)
        #update score
        self.timer = QTimer(self)
        self.timer.timeout.connect(self.update_score)
        self.timer.start(100)

    def shoot_button_clicked(self):
        self.anim_area.ball.shoot = True
        self.QS_shot.play()

    def update_score(self):
        self.score = self.anim_area.score
        self.score_label.setText("Score: " + str(self.score))


def main():
    app = QApplication(sys.argv)
    w = Simple_animation_window()
    w.show()
    return app.exec()

if __name__ == "__main__":
    sys.exit(main())
