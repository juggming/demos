#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

typedef struct {
    int cost;
    int supplier;
} Partinfo;

typedef struct {
    int n_parts;
    struct SUBASSYPART {
        char partno[16];
        short quan;
    } *part;
}  Subassyinfo;

typedef struct {
    char partno[16];
    int quan;
    enum {PART, SUBASSY} type;
    union {
        Partinfo *part;
        Subassyinfo *subassy;
    } info;
} Invrec;


Invrec *create_subassy_record(int n_parts)
{
    Invrec *new_rec;

    new_rec = malloc(sizeof(Invrec));
    if(new_rec != NULL) {
        new_rec->info.subassy = malloc(n_parts * (sizeof(Subassyinfo)));
        if(new_rec->info.subassy != NULL) {
            new_rec->info.subassy->part = malloc(n_parts *sizeof(struct SUBASSYPART));
            if(new_rec->info.subassy->part != NULL) {
                new_rec->type = SUBASSY;
                new_rec->info.subassy->n_parts = n_parts;
                return new_rec;
            }
            free(new_rec->info.subassy);
        }
        free(new_rec);
    }
    return NULL;
}

void discard_inventory_record(Invrec *record)
{
    assert(record);
    switch(record->type){
        case SUBASSY:
            free(record->info.subassy->part);
            free(record->info.subassy);
            break;
        case PART:
            free(record->info.part);
            break;
    }
    free(record);
}
