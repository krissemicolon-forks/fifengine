/***************************************************************************
 *   Copyright (C) 2005-2008 by the FIFE team                              *
 *   http://www.fifengine.de                                               *
 *   This file is part of FIFE.                                            *
 *                                                                         *
 *   FIFE is free software; you can redistribute it and/or modify          *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA              *
 ***************************************************************************/

#ifndef FIFE_ENGINESETTINGS_H
#define FIFE_ENGINESETTINGS_H

// Standard C++ library includes
#include <vector>

// 3rd party library includes

// FIFE includes
// These includes are split up in two parts, separated by one empty line
// First block: files included from the FIFE root src directory
// Second block: files included from the same folder
#include "util/exception.h"

namespace FIFE {
	class NotSupported;

	/** This class defines the engine settings on engine init
	 *
	 */
	class EngineSettings {
	public:
		/** Constructor
		 */
		EngineSettings();
		
		/** Destructor
		 */
		~EngineSettings();
		
		/** Validates settings. On invalid settings, throws NotSet with message
		 */
		void validate() const throw(NotSet);
		
		/** Sets bits per pixel
		 * @see getPossibleBitsPerPixel
		 */
		void setBitsPerPixel(unsigned int bitsperpixel) throw(NotSupported);
		
		/** Gets currently set bits per pixel value
		 */
		unsigned int getBitsPerPixel() const { 
			return m_bitsperpixel;
		}
		
		/** Gets all possible bits per pixel values
		 */
		std::vector<unsigned int> getPossibleBitsPerPixel() const;
		
		/** Sets fullscreen / windowed mode
		 */
		void setFullScreen(bool fullscreen) { 
			m_fullscreen = fullscreen;
		}
		
		/** True, if set to fullscreen. False = windowed
		 */
		bool isFullScreen() const { 
			return m_fullscreen;
		}
		
		/** Sets initial engine sound volume
		 *  @see getInitialMaxVolume
		 */
		void setInitialVolume(float volume) throw(NotSupported);
		
		/** Gets initial engine sound volume
		 */
		float getInitialVolume() const {
			return m_initialvolume;
		}
		
		/** Gets maximum volume that can be set
		 */
		float getMaxVolume() const;
		
		/** Sets name for renderbackend
		 *  @see getPossibleRenderBackends
		 */
		void setRenderBackend(const std::string& renderbackend) throw(NotSupported);
		
		/** Gets currently set renderbackend name
		 */
		const std::string getRenderBackend() const {
			return m_renderbackend;
		}
		
		/** Gets all possible renderbackend names
		 */
		std::vector<std::string> getPossibleRenderBackends();
		
		/** Sets if fake alpha is removed in SDL renderbackend
		 */
		void setSDLRemoveFakeAlpha(bool sldremovefakealpha);
		
		/** Tells if fake alpha is removed in SDL renderbackend
		 */
		bool isSDLRemoveFakeAlpha(bool sldremovefakealpha) const {
			return m_sldremovefakealpha;
		}
		
		/** Sets screen width (pixels)
		 */
		void setScreenWidth(unsigned int screenwidth);
		
		/** Gets screen width (pixels)
		 */
		unsigned int getScreenWidth() const {
			return m_screenwidth;
		}
		
		/** Sets screen height (pixels)
		 */
		void setScreenHeight(unsigned int screenheight);
		
		/** Gets screen height (pixels)
		 */
		unsigned int getScreenHeight() const {
			return m_screenheight;
		}
		
		/** Sets path for default font
		 */
		void setDefaultFontPath(const std::string& defaultfontpath) throw(NotFound);
		
		/** Sets current path for default font
		 */
		std::string getDefaultFontPath() const {
			return m_defaultfontpath;
		}
		
		/** Sets size for default font
		 */
		void setDefaultFontSize(const unsigned int defaultfontsize);
		
		/** Gets size for default font
		 */
		unsigned int getDefaultFontSize() const {
			return m_defaultfontsize;
		}
		
		/** Sets glyphs for default font
		 */
		void setDefaultFontGlyphs(const std::string& defaultfontglyphs);
		
		/** Gets current glyphs for default font
		 */
		std::string getDefaultFontGlyphs() const {
			return m_defaultfontglyphs;
		}
	
	
	private:
		unsigned int m_bitsperpixel;
		bool m_fullscreen;
		float m_initialvolume;
		std::string m_renderbackend;
		bool m_sldremovefakealpha;
		unsigned int m_screenwidth;
		unsigned int m_screenheight;
		
		std::string m_defaultfontpath;
		unsigned int m_defaultfontsize;
		std::string m_defaultfontglyphs;
	};

}//FIFE

#endif

