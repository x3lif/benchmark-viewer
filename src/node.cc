// Copyright (C) 2015, Romain Goffe <romain.goffe@gmail.com>
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License as
// published by the Free Software Foundation; either version 2 of the
// License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful, but
// WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
// 02110-1301, USA.
//******************************************************************************
#include "node.hh"

#include <QDebug>

CNode::CNode() :
m_start(),
m_stop(),
m_steps(),
m_label(),
m_category(),
m_level(0)
{
}

CNode::~CNode(){}

const QDateTime & CNode::start() const
{
  return m_start;
}

void CNode::setStart(const QDateTime & p_dateTime)
{
  m_start = p_dateTime;
}

const QDateTime & CNode::stop() const
{
  return m_stop;
}

void CNode::setStop(const QDateTime & p_dateTime)
{
  m_stop = p_dateTime;
}

const QList<QDateTime> & CNode::steps() const
{
  return m_steps;
}

void CNode::setSteps(const QList<QDateTime> & p_steps)
{
  m_steps = p_steps;
}

void CNode::addStep(const QDateTime & p_dateTime)
{
    m_steps << p_dateTime;
}

const QString & CNode::label() const
{
  return m_label;
}

void CNode::setLabel(const QString & p_label)
{
  m_label = p_label;
}

const QString & CNode::category() const
{
  return m_category;
}

void CNode::setCategory(const QString & p_category)
{
  m_category = p_category;
}

int CNode::level() const
{
  return m_level;
}

void CNode::setLevel(const int p_level)
{
  m_level = p_level;
}

bool CNode::isValid() const
{
  return !m_start.isNull() && !m_stop.isNull();
}

qint64 CNode::duration() const
{
  return m_stop.toMSecsSinceEpoch() - m_start.toMSecsSinceEpoch();
}

QString CNode::toString() const
{
  return QString("%1 (%2)")
  .arg(label())
  .arg(mSecsToString(duration()));
}

QString CNode::mSecsToString(const qint64 p_msecs)
{
  const int ms = p_msecs;
  const int h  = p_msecs / (60  * 60 * 1000);
  const int mn = p_msecs / (60 * 1000) - h * 60;
  const int s  = p_msecs / 1000 - mn * 60;

  if (h > 1)
  {
    return QString("%1h %2mn").arg(h).arg(mn);
  }
  else if (mn > 1)
  {
    return QString("%1mn %2s").arg(mn).arg(s);
  }
  else if (s > 1)
  {
    return QString("%1s %2ms").arg(s).arg(ms);
  }
  else
  {
    return QString("%1ms").arg(ms);
  }
}
