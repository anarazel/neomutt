/**
 * @file
 * Test code for mutt_addr_qualify()
 *
 * @authors
 * Copyright (C) 2019 Richard Russon <rich@flatcap.org>
 *
 * @copyright
 * This program is free software: you can redistribute it and/or modify it under
 * the terms of the GNU General Public License as published by the Free Software
 * Foundation, either version 2 of the License, or (at your option) any later
 * version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
 * details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#define TEST_NO_MAIN
#include "acutest.h"
#include "config.h"
#include "mutt/mutt.h"
#include "address/lib.h"

void test_mutt_addr_qualify(void)
{
  // void mutt_addr_qualify(struct Address *addr, const char *host);

  {
    mutt_addr_qualify(NULL, "example.com");
    TEST_CHECK_(1, "mutt_addr_qualify(NULL, \"example.com\")");
  }

  {
    struct Address addr = { 0 };
    mutt_addr_qualify(&addr, NULL);
    TEST_CHECK_(1, "mutt_addr_qualify(&addr, NULL)");
  }
}
