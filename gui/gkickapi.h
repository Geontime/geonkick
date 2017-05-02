#ifndef GKICK_API_H
#define GKICK_API_H

/**
 * File name: gkickapi.h
 * Project: GeonKick
 *
 * Copyright (C) 2015 Iurie Nistor
 * Email: nistor@iurie.org
 *
 * This file is part of GeonKick.
 *
 * waveToMp3 is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

#include <memory>
#include <vector>
#include <QPolygonF>
#include <QObject>

#include "geonkick.h"

class GKickOscillator;

class GKickApi: public QObject
{
  Q_OBJECT
  
 public:

  GKickApi(void);
  ~GKickApi();
  void setError(bool b);
  bool hasErrors(void);
  std::vector<std::unique_ptr<GKickOscillator>> getOscillators(void);
  QPolygonF getOscEvelopePoints(int osc, int envelope);
  void addOscEnvelopePoint(int osc,
			    int envelope,
			    const QPointF &point);

   void removeOscEvelopePoint(int osc,
			      int envelope,
			      int index);
   void updateOscEvelopePoint(int osc,
			      int envelope,
			      int index,
			      const QPointF &point);

   void setOscFunction(int oscillatorIndex,
		       enum geonkick_osc_func_type type);

   void setKickLength(double len);
   double getKickLength(void);
 signals:
   void kickLengthUpdated(double len);

 protected:
     
 private:
	bool isError;
      	struct geonkick *gKickApi;	
};

#endif
