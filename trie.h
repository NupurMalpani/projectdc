/*Copyright (C) 2015  Nupur Malpani
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include"trielist.h"
typedef struct result{
	union data{
		trienode* last;
		int value;
	}d;
	int found;
	int level;
}result;
typedef struct trienode *trie;

void add(char *tn,trie *t);/*given  a node insert in the trie*/
void inittrie(trie *t);/*intialize a trie*/
void printtrie(trie t);/*prints it levelwise*/
result *searchintrie(char *m, trie *root);/*search in tree if not found returns the address of last node matched*/
int present(char *m,trie *t);
