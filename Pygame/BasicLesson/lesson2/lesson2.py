# Purpose : Test

import pyttsx3
import pygame

# initialize pygame
pygame.init();
screen= pygame.display.set_mode((900,700))
pygame.display.set_caption("lesson1")
widthScreen = 900;
# initialize about characters
x=50;
y=650;
width=20;
height=40;
vel=5;

# initialize about variable jump
isJump = False
jumpCount = 10

# build the loop for the game will run
run = True
while run:
    pygame.time.delay(100)  # this delay for the game
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            run=False
    keys = pygame.key.get_pressed()
    if keys[pygame.K_LEFT] and x > vel:
        x -= vel
    if keys[pygame.K_RIGHT] and x < widthScreen - vel - width:
        x += vel
    # we make sure there is no up / down when jumping
    if not(isJump):
        if keys[pygame.K_UP] and y > vel:
            y -= vel
        if keys[pygame.K_DOWN] and y < 700 - vel - height:
            y += vel
        if keys[pygame.K_SPACE]:
            isJump = True
    else:
        if jumpCount >= -10:
            neg =1;
            if jumpCount < 0:
                neg = -1
            y -= (jumpCount ** 2) * 0.5* neg
            jumpCount -=1
        else:
            # return to the orignal after jump
            isJump = False;
            jumpCount = 10;
    screen.fill((0,0,0))
    pygame.draw.rect(screen,(255,0,0),(x,y,width,height))
    pygame.display.update()

pygame.quit()
