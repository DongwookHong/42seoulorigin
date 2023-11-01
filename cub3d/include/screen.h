#ifndef SCREEN_H
# define SCREEN_H

# define WINDOW_WIDTH	640
# define WINDOW_HEIGHT	480

# define KEY_W				13
# define KEY_A				0
# define KEY_S				1
# define KEY_D				2
# define KEY_LEFT			123
# define KEY_RIGHT			124
# define KEY_FORWARD 		126
# define KEY_BACKWARD		125
# define KEY_ESC			53

# define EVENT_KEY_PRESS	2
# define EVENT_KEY_RELEASE	3
# define EVENT_KEY_EXIT		17



typedef enum e_bool
{
	FALSE,
	TRUE
}	t_bool;

typedef struct s_img{
    
unsigned long long width;
unsigned long long height;

} t_img;


#endif