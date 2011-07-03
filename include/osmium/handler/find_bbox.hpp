#ifndef OSMIUM_HANDLER_FIND_BBOX_HPP
#define OSMIUM_HANDLER_FIND_BBOX_HPP

/*

Copyright 2011 Jochen Topf <jochen@topf.org> and others (see README).

This file is part of Osmium (https://github.com/joto/osmium).

Osmium is free software: you can redistribute it and/or modify it under the
terms of the GNU Lesser General Public License or (at your option) the GNU
General Public License as published by the Free Software Foundation, either
version 3 of the Licenses, or (at your option) any later version.

Osmium is distributed in the hope that it will be useful, but WITHOUT ANY
WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A
PARTICULAR PURPOSE. See the GNU Lesser General Public License and the GNU
General Public License for more details.

You should have received a copy of the Licenses along with Osmium. If not, see
<http://www.gnu.org/licenses/>.

*/

namespace Osmium {

    namespace Handler {

        class FindBbox : public Base {

        public:

            FindBbox() : Base(), m_minlon(1000), m_maxlon(-1000), m_minlat(1000), m_maxlat(-1000) {
            }

            double minlon() const {
                return m_minlon;
            }

            double maxlon() const {
                return m_maxlon;
            }

            double minlat() const {
                return m_minlat;
            }

            double maxlat() const {
                return m_maxlat;
            }

            void node(Osmium::OSM::Node* node) {
                if (node->get_lon() < m_minlon) m_minlon = node->get_lon();
                if (node->get_lon() > m_maxlon) m_maxlon = node->get_lon();
                if (node->get_lat() < m_minlat) m_minlat = node->get_lat();
                if (node->get_lat() > m_maxlat) m_maxlat = node->get_lat();
            }

            void after_nodes() const {
                throw Osmium::Input::StopReading();
            }

        private:

            double m_minlon;
            double m_maxlon;
            double m_minlat;
            double m_maxlat;

        }; // class FindBbox

    } // namespace Handler

} // namespace Osmium

#endif // OSMIUM_HANDLER_FIND_BBOX_HPP
