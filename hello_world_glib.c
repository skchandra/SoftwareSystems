/*
 * hello_world_glib.c
 * 
 * Copyright 2015 Kiki <kiki@kiki-Latitude-E6430>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */


#include <stdio.h>
#include <glib.h>

int main(int argc, char** argv) {
     gchar *filename;
     gchar **array;
     GHashTable* word_freq = g_hash_table_new(GHashFunc hash, GEqualFunc key_equal);
     
     if (argc > 1) {
		filename = argv[1];
     } else {
		filename = "alchemist.txt";
     }
     
     FILE *file = g_fopen(filename, "r");
     if (file == NULL) {
		perror (filename);
		exit (-10);
     }
     
     int i;
     
     gchar *res = fgets(line, sizeof(line), file);
     while (res != NULL) {
		gchar *res = fgets(line, sizeof(line), file);
		array = g_strsplit(line, " ", 0);
		
		for (i=0; array[i] != NULL; i++) {
			gint *val = (gint*) g_hash_table_lookup(hash, array[i]);
			if (val == NULL) {
				gchar *key = array[i];
				gint *val = g_new(gint, 1);
				val = 1; 
				g_hash_table_insert(hash, key, val);
			} else {
				*val+=1;
			}
		}
		g_strfreev (array);
    }
    
    fclose (file);
         
}

