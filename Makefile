MAINE = src/mainExemple
MAIN = src/main
MAINT = src/mainTest
MAINA = src/mainAffichage

PIXEL = src/Pixel
IMAGE = src/Image

MAIN_OUT = bin/main.out
EXEMPLE_OUT = bin/exemple
TEST_OUT = bin/test

MAINE_O = obj/mainExemple.o
MAINT_O = obj/mainTest.o
MAINA_O = obj/mainAffichage.o

EXEMPLE_OUT_O = bin/exemple
TEST_OUT_O = bin/test
AFFICHER_OUT_O = bin/affichage
IMAGE_O = obj/Image.o
PIXEL_O = obj/Pixel.o

INCLUDE_DIR_SDL = -I/usr/include/SDL2
PETIT_L = -lSDL2 -lSDL2_ttf -lSDL2_image





all: $(EXEMPLE_OUT_O) $(TEST_OUT_O) $(AFFICHER_OUT_O)

$(AFFICHER_OUT_O): $(MAINA_O) $(IMAGE_O) $(PIXEL_O)
	g++ -g $(MAINA_O) $(IMAGE_O) $(PIXEL_O) -o $(AFFICHER_OUT_O) $(PETIT_L)
	
$(EXEMPLE_OUT_O): $(MAINE_O) $(IMAGE_O) $(PIXEL_O)
	g++ -g $(MAINE_O) $(IMAGE_O) $(PIXEL_O) -o $(EXEMPLE_OUT_O) $(PETIT_L)
	
$(TEST_OUT_O): $(MAINT_O) $(IMAGE_O) $(PIXEL_O)
	g++ -g $(MAINT_O) $(IMAGE_O) $(PIXEL_O) -o $(TEST_OUT_O) $(PETIT_L)


$(MAINA_O): $(PIXEL).h $(IMAGE).h $(MAINA).cpp
	g++ -g -Wall -c $(INCLUDE_DIR_SDL) $(MAINA).cpp -o $(MAINA_O)

$(MAINE_O): $(PIXEL).h $(IMAGE).h $(MAINE).cpp
	g++ -g -Wall -c $(INCLUDE_DIR_SDL) $(MAINE).cpp -o $(MAINE_O)
	
$(MAINT_O): $(PIXEL).h $(IMAGE).h $(MAINT).cpp
	g++ -g -Wall -c $(INCLUDE_DIR_SDL) $(MAINT).cpp -o $(MAINT_O)


$(IMAGE_O): $(PIXEL).h $(IMAGE).h $(IMAGE).cpp
	g++ -g -Wall -c $(INCLUDE_DIR_SDL) $(IMAGE).cpp -o $(IMAGE_O)
	
$(PIXEL_O): $(PIXEL).h $(PIXEL).cpp
	g++ -g -Wall -c $(INCLUDE_DIR_SDL) $(PIXEL).cpp -o $(PIXEL_O)

clean_o:
	rm obj/*.o bin/*.o

clean:
	rm bin/*.out obj/*.out $(EXEMPLE_OUT_O) $(TEST_OUT_O) $(AFFICHER_OUT_O) obj/*.o bin/*.o src/*.o

valgrind:
	valgrind $(MAIN_OUT)

v_e:
	valgrind $(EXEMPLE_OUT_O)

v_t:
	valgrind $(TEST_OUT_O)

v_a:
	valgrind $(AFFICHER_OUT_O)






