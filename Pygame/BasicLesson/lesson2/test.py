# Start over again about game designing in Python
import pygame as py
#initialize game
py.init()
py.display.set_caption("Hello")
screen = py.display.set_mode((500,500))

# initialize about characters images

x = 40
y = 450
width = 40
height = 60
vel = 10
# initialize about the jumppart
jumpCount = 10
isJump = False
# run the loop
run = True
while run:
    py.time.delay(100)
    # thinks about event of game working
    for event in py.event.get():
        if event.type == py.QUIT:
            run = False
    # make the character
    # py.draw.rect(screen,(254,0,0),(x,y,width, height))
    # Get the keys to play the games or mechanism how to play it
    keys= py.key.get_pressed()
    if keys[py.K_LEFT]:
        x -= vel
    if keys[py.K_RIGHT]:
        x += vel
    if not(isJump):
        if keys[py.K_UP]:
            y -= vel
        if keys[py.K_DOWN]:
            y += vel
        if keys[py.K_SPACE]:
            isJump = True
    else:
        if jumpCount >= -10:
            neg = 1
            if jumpCount < 0:
                neg = -1
            y -= (jumpCount**2) * 0.5 * neg
            jumpCount -=1
        else:
            isJump = False
            jumpCount = 10
    screen.fill((0,0,0))
    py.draw.rect(screen,(254,0,0),(x,y, width, height))
    py.display.update()

py.quit()
