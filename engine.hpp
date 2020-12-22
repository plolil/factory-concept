#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_thread.h>
#include <SDL2/SDL_image.h>
#include <vector>
#include <string>

#define CHUNK_SIZE 16


namespace engine {

	template <class T>
	class allocator {
		class value_type = T;
		pointer allocate(size_type n) {
			SDL_calloc(n, sizeof(T));
		}
		void deallocate(T* p, std::size_t n) {
			for(int i = 0; i < n; i++) {
				SDL_free(p[n])
			}
		}
	};

	template <typename T>
	class Vector2 {
		public:
		T x;
		T y;
		Vector2() {
			x = 0;
			y = 0;
		}
		Vector2(T xin, T yin) {
			x = xin;
			y = yin;
		}
	};
	class component {
		public:
		int setup();
		int start();
		int update(Uint32 DeltaT);
		int stop();
		int setdown();
	};

	class entity {
		protected:
		std::vector<component> components;
		public:
		Vector2<float> *pos;
		long id;
		bool visual;
		entity(long id, float startingx, float startingy);
	};

	class hitbox {
		public:
		Vector2<float> dimensions;
		Vector2<float> pos;
		hitbox();
		hitbox(float width, float height, float x, float y) {
			dimensions.x = width;
			dimensions.y = height;
			pos.x = x;
			pos.y = y;
		}
	};

	class speedmod {
		float xUP;
		float xDOWN;
		float yUP;
		float yDOWN;
		speedmod(float u, float d, float l, float r) {

		}
	};

	class travelprops {
		hitbox landbox;
		hitbox airbox;
	};

	class tile {
		char imagepath[50];
		Vector2<long> chunk;
		Vector2<long> pos;
	};

	class tilemap {
		std::vector<std::vector<tile>> tileset;
	};
}