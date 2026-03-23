*This project has been created as part of the 42 curriculum by egiraud and barmarti*
# miniRT
A (very) basic raytracer with some cool addons like multithreading and other optimisations.  
The goal of the project is to make your first step in the vast world of **computer graphics** by recreating.... light!  

---

## How it works
With the goal of recreating how light works into computer graphics we need to simulate photons. Photons are light particules that we will simulate by tracing rays (so vectors).  
In real life the majority of light particules that a light source emit don't get to our eyes, so for a raytracer we do the other way. Instead of light to eyes, we do eyes (camera) to light.  
So we cast a lot of rays from the "eye", check intersection mathematically with objects, then trace to lights sources to compute for each pixel which color it should be on the screen. And that's all.... sounds simple when you dont have to catch up with hundreds of hour of maths.

---

## How to use ?
Clone the project, then, inside the project simply ```make``` and type ```./miniRT scenes/<scene> [-fs] [-aa]``` where -fs is for rendering fullscreen and -aa to toggle antialiasing so object edges are smoother (takes significantly more process time).  
  
We have some scene already ready to use but you can customise them by editing the .rt files, one object per line, in the order given (stricly). First letter(s) are the identifier. Capital letters means that the element can be declared only once in the scene.    
#### Mandatory objects :  
* Ambiant Lightning - A <lightning ratio range [0.0-1.0]> <R,G,B value range [0-255]>  
Example : ```A 0.3 255,255,255```  
* Camera - C <x,y,z coords of the camera> <orientation normalized vector3 range [-1,1] for each x,y,z axis> <horizontal fov range [0,180]>  
Example : ```C -50,0,20 0,0,-0.3 70```  
* Light - L <x,y,z coords of the light source> <lightning ratio range [0.0-1.0]> <R,G,B value range [0-255]>  
Example : ```L 30,-5,15 0.8 255,255,255``` 
#### Optional objects :
* Sphere - sp <x,y,z coords of the center> <sphere diameter> <R,G,B value range [0-255]>  
Example : ```sp -8,16,90 33 255,0,10```  
* Cylinder - sp <x,y,z coords of the center> <cylinder axis orientation normalized vector3 range [-1,1]> <cylinder diameter> <cylinder height> <R,G,B value range [0-255]>  
Example : ```cy 4,9,25 0.0,1.0,-0.3 4 16.3 0,10,255```  
* Plane - sp <x,y,z coords of a point of the plane> <normal normalized vector3 range [-1,1]> <R,G,B value range [0-255]>  
Example : ```sp 0,-10,67 0.0,1.0,0.0 0,255,10```  

## Ressources
* **The most usefull ressource**, detailing about everything you need for your basic raytracer and even more :
The [books by Peter Shirley, Trevor David Black and Steve Hollasch](https://raytracing.github.io) "Raytracing in One Weekend", "Raytracing the Next Week" and "Ray Tracing the Rest of your Life"  
* **Other ressources** we used at some point :  
Videos from the youtube channel [QuantitativeBytes](https://www.youtube.com/playlist?list=PL3WoIG-PLjSt54LvzY2SuBQDl-cXa11Tm) (what a nerd).  
Also this serie of videos by [The Cherno](https://www.youtube.com/playlist?list=PLlrATfBNZ98edc5GshdBtREv5asFW3yXl)  
Then a lot of articles for certain specific points like matrices with [this very usefull PDF](https://physique.cmaisonneuve.qc.ca/svezina/projet/ray_tracer/download/Conference-Le_ray_tracer-Les_calculs_matriciels_dans_le_ray_tracing.pdf) or [this StackOverflow discussion](https://stackoverflow.com/questions/2624422/efficient-4x4-matrix-inverse-affine-transform).  
[This article](https://www.scratchapixel.com/lessons/3d-basic-rendering/ray-tracing-generating-camera-rays/generating-camera-rays.html) also for setup the camera was very usefull (the entire site is too). 
  
We are also adept of talking with peers and getting help for notions we don't understand so shoutout to some other student like ldubois, acamargo and other !  
  
IA was used for clarifying maths notions mostly, no code generated.  

---

## Some renders
![0](/screenshots/0.png)
![1](/screenshots/1.png) 
![2](/screenshots/2.png)
![3](/screenshots/3.png)

