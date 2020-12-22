#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_thread.h>
#include <SDL2/SDL_image.h>
#include <vector>


namespace engine {
	template <typename T>
	class Vector2 {
		public:
		T x;
		T y;
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

	class tile {
		
	};
}