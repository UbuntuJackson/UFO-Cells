//  SuperTux
//  Copyright (C) 2006 Matthias Braun <matze@braunis.de>
//                2023 Vankata453
//
//  This program is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program.  If not, see <http://www.gnu.org/licenses/>.

#ifndef HEADER_BRUX_SQUIRREL_SQUIRREL_ERROR_HPP
#define HEADER_BRUX_SQUIRREL_SQUIRREL_ERROR_HPP

#include <squirrel.h>

#include <string>
#include <stdexcept>

/** Exception class for squirrel errors, it takes a HSQUIRRELVM and uses
 * sq_geterror() to retrieve additional information about the last error that
 * has occurred and creates a readable message from that.
 */
class SquirrelError final : public std::exception
{
private:
	std::string m_message;

public:
	SquirrelError(HSQUIRRELVM v, const std::string& message) throw();

	const char* what() const throw() { return m_message.c_str(); }
};

#endif

/* EOF */
