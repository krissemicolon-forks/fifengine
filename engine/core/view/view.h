/***************************************************************************
 *   Copyright (C) 2005-2007 by the FIFE Team                              *
 *   fife-public@lists.sourceforge.net                                     *
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

#ifndef FIFE_VIEW_VIEW_H
#define FIFE_VIEW_VIEW_H

// Standard C++ library includes
#include <list>

// 3rd party library includes
#include <SDL.h>

// FIFE includes
// These includes are split up in two parts, separated by one empty line
// First block: files included from the FIFE root src directory
// Second block: files included from the same folder
#include "rendererbase.h"

namespace FIFE {
	class Camera;
	class RenderBackend;
	class ImagePool;
	class AnimationPool;
	class Instance;
	class Object;
	class Action;

	class View: public RendererListener {
	public:
		/** Constructor
		 */
		View(RenderBackend* renderbackend);

		/** Destructor
		 */
		~View();

		/** Adds new renderer on the view. Ownership is transferred to the view.
		 * After addition, renderer is active for all cameras
		 */
		void addRenderer(RendererBase* renderer);

		/** Gets renderer with given name
		 */
		RendererBase* getRenderer(const std::string& name);

		/** Adds new camera on view.
		 *  After creation, camera gets rendered by the added renderers
		 */
		Camera* addCamera(const std::string& id, Layer *layer, Rect viewport, ExactModelCoordinate emc);

		/** Get a camera by its identifier.
 		 */
		Camera* getCamera(const std::string& id);

		/** Get a list containing all cameras.
		 * @return std::list<Camera*>& Cameralist
		 */
		std::vector<Camera*>& getCameras() { return m_cameras; }

		/** Removes given camera from the view.
		 */
		void removeCamera(Camera* camera);

		/** Clears all cameras from view
		 */
		void clearCameras();

		/** resets active layer information to be reseted on all renderers.
		 *  View fetches all layers from cameras and activate them on each renderer.
		 */
		void resetRenderers();

		/** Causes view to render all cameras
		 */
		void update(ImagePool*,AnimationPool*);

		void onRendererPipelinePositionChanged(RendererBase* renderer);
		void onRendererEnabledChanged(RendererBase* renderer);


	private:
		// list of cameras managed by the view
		std::vector<Camera*> m_cameras;
		RenderBackend* m_renderbackend;
		// list of renderers managed by the view
		std::map<std::string, RendererBase*> m_renderers;
		std::list<RendererBase*> m_pipeline;
	};

}
#endif
