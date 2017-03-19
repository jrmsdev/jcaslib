#include <jclib/db.h>
#include <stdlib.h>

void
dbdata_free (dbdata *dat)
{
	for (size_t i = 0; i < dat->len; i++)
	{
		free (dat->db[i]->key);
		dat->db[i]->key = NULL;
		free (dat->db[i]->val);
		dat->db[i]->val = NULL;
		free (dat->db[i]);
		dat->db[i] = NULL;
	}
	dat->len = 0;
	free (dat->db);
	dat->db = NULL;
	free (dat);
	dat = NULL;
}
