/**
 * @file
 * Test code for mutt_addresslist_parse()
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

void test_mutt_addresslist_parse(void)
{
  // void mutt_addresslist_parse(struct AddressList *top, const char *s);

  {
    struct AddressList alist = TAILQ_HEAD_INITIALIZER(alist);
    mutt_addresslist_parse(&alist, "apple");
    TEST_CHECK(mutt_addresslist_first(&alist) != NULL);
    mutt_addresslist_free_all(&alist);
  }

  {
    struct AddressList alist = TAILQ_HEAD_INITIALIZER(alist);
    mutt_addresslist_parse(&alist, NULL);
    TEST_CHECK(mutt_addresslist_first(&alist) == NULL);
  }
}