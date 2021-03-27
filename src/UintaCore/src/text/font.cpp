#include "font_loader.h"

namespace uinta {

	Font Font::loadFont(const char *trueTypePath) {
		return FontLoader::loadFond(trueTypePath);
	}

	stbtt_aligned_quad Font::getTexturedQuadInfo(const char c, float_t *xCursor, float_t *yCursor) {
		static stbtt_aligned_quad quad;
		stbtt_GetBakedQuad(_stbttBakedChar, Font::ATLAS_WIDTH, Font::ATLAS_HEIGHT, c - 32, xCursor, yCursor, &quad, 0);
		return quad;
	}

}
