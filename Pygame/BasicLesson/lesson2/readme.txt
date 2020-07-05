this is basic to learn pygame
https://www.youtube.com/watch?v=FfWpgLFMI7w
https://www.youtube.com/watch?v=i6xMBig-pP4

// 2nd link is fragment of each tutorial so it will be better to break a big chunk for coding lesson into small sections

Step1 : Import pygame library
import pygame
step2: initilize the pygame
pygame.init();
# this is test by me
import pygame

#initial
pygame.init()
pygame.display.set_caption("Luan")
screen = pygame.display.set_mode((500,500))

# set the character information
x = 20
y = 40
width = 40
height= 50
vel = 10

# run the loop
run = True
while run:
    pygame.time.delay(100)
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
          run = False
    pygame.draw.rect(screen,(250,0,0),(x,y,width, height))
    pygame.display.update()
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
pygame.quit()
step3: Create a window or how big your screen do you want to implement your game into

screen = pygame.display.set_mode((width, height))
// then set the caption for the screen
pygame.display.set_caption("name")

step4 : Character Move
There are couple smaller sections so we have to pay attention to.
Character should have their own dimension like wdith, height and velocity
    X,Y coordinator
    width, height
    velocity
Ex:
x,y=50,50
width, height=20,40
velocity =5

Step5: thinks about looping to check about how game should be work
like collision, how to defeat the enemy, movements, highly recomended about while loop with variable run == True and then turn run==False if want to break the loop
we also must check about events from users like
click the keys, move cursors,
pygame.event.get()
event.type() # mean user press the button ESC to exit
pygame.QUIT # quit inside the loop
pygame.quit()

Step6: draw the characters
we can use some of the pygame.draw.rec or .cir... to do with the character image
http://www.petercollingridge.co.uk/tutorials/pygame-physics-simulation/drawing-circles/
pygame.draw.rec(win, (255,0,0), (x,y,width,height))
                       color        coordinator
this is also will help to build circle also please check the above link
# this might prefer to another parameters
Then must use to show the builded character
pygame.display.update()

step7: now make character move
check if whether any keys has been pressed

keys=pygame.key.get_pressed()

    if keys[pygame.K_LEFT]:
        x -= vel
    if keys[pygame.K_RIGHT]:
        x += vel
    if keys[pygame.K_DOWN]: # this one is just careful because it coordinator does not make sense when we try to understand it
        y += vel
    if keys[pygame.K_UP]:
        y -= vel
# to eliminate all the shadow we must have to fill the color
        screen.fill((0,0,0))

###################
JUMPING AND BOUNDARY
Lesson 2: We have finish build screen, character and all the moving parts but somehow the character can only outside of the territory so we have to fix it by
    _ not allow it to move out of screen
Note: origin coordinator is right at the top left and have coordinator at (0,0)
----->
-
-
v
Character coordinator is stored by coordinator by the top left coordinator
Pay attention to the if statement in the while loop, make sure we put condition in there so that the character wont go beyond the teritory
## build the jumping
initilize about declare variables

isJump= False
jumpCount = 10

# we will use the key Space and make sure we dont let up down works when we jump

# algorithms of jumping is go up faster then stop a bit and then go down.
Pay attention to the if and else statement in the code

# There are some things to pay attention,especialty that is the neg variable like not just jump to all the way

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
