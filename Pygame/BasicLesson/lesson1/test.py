# Start over again about game designing in Python
import pygame as py
#initialize game
py.init()
py.display.set_caption("Hello")
screen = py.display.set_mode((500,500))

# initialize about characters images

x = 40
y = 50
width = 40
height = 60
vel = 10

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
    if keys[py.K_UP]:
        y -= vel
    if keys[py.K_DOWN]:
        y += vel
    screen.fill((0,0,0))
    py.draw.polygon(screen,(254,0,0),[(10,15),(20,30), (40,50),(35,45)],0)
    py.display.update()

py.quit()
