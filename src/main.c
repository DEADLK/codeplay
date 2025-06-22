#define CLAY_IMPLEMENTATION
#include "clay.h"

typedef struct {
    void* memory;
    uintptr_t offset;
} Arena;

Arena frameArena = {};

double windowWidth = 1024, windowHeight = 768;

#define RAYLIB_VECTOR2_TO_CLAY_VECTOR2(vector) (Clay_Vector2) { .x = (vector).x, .y = (vector).y }

CLAY_WASM_EXPORT("SetScratchMemory") void SetScratchMemory(void * memory) {
    frameArena.memory = memory;
}

CLAY_WASM_EXPORT("UpdateDrawFrame") Clay_RenderCommandArray UpdateDrawFrame(float width, float height, float mouseWheelX, float mouseWheelY, float mousePositionX, float mousePositionY, bool isTouchDown, bool isMouseDown, bool arrowKeyDownPressedThisFrame, bool arrowKeyUpPressedThisFrame, bool dKeyPressedThisFrame, float deltaTime) {
    frameArena.offset = 0;
    windowWidth = width;
    windowHeight = height;

    Clay_SetLayoutDimensions((Clay_Dimensions){ windowWidth, windowHeight });

    Clay_BeginLayout();

    CLAY_TEXT(CLAY_STRING("Clay - UI Library"), CLAY_TEXT_CONFIG({ .fontSize = 24, .textColor = {255, 0, 255, 255} }));
    // CLAY({
    //     .layout = {
    //         .sizing = {
    //             CLAY_SIZING_FIXED(150),
    //             CLAY_SIZING_FIXED(100)
    //         }
    //     },
    //     .backgroundColor = { 255, 0, 0, 255 }
    // }) {

	// 	CLAY({
	// 	    .layout = {
	// 	        .sizing = {
	// 	            CLAY_SIZING_FIXED(50),
	// 	            CLAY_SIZING_FIXED(50)
	// 	        }
	// 	    },
	// 	    .backgroundColor = {255, 255, 0, 255}
	// 	}) {}
    // }
    Clay_RenderCommandArray renderCommands = Clay_EndLayout();

    return renderCommands;
}

int main() {
	return 0;
}
