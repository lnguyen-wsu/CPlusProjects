# Purpose : Test

import pyttsx3
import pygame

# initialize pygame
pygame.init();
screen= pygame.display.set_mode((900,700))
pygame.display.set_caption("lesson1")

# initialize about characters
x=50;
y=50;
width=20;
height=40;
vel=5;

# build the loop for the game will run
run = True
while run:
    pygame.time.delay(100)  # this delay for the game
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            run=False
    keys = pygame.key.get_pressed()
    if keys[pygame.K_LEFT]:
        x -= vel
    if keys[pygame.K_RIGHT]:
        x += vel
    if keys[pygame.K_DOWN]:
        y += vel
    if keys[pygame.K_UP]:
        y -= vel
    screen.fill((0,0,0))
    pygame.draw.circle(screen,(255,64,0),(x,y),15,1)
    pygame.display.update()
pygame.quit()
