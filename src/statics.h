#ifndef STATICS
#define STATICS

#define PROFILE_HUE_SIZE 255

typedef struct{
	int r;
	int g;
    int b;
}PROFILE_HUE_RGB;

PROFILE_HUE_RGB averageRGB(PROFILE_HUE_RGB[], double[], int);

#endif 