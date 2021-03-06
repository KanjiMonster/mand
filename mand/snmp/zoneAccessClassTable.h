/*
 * Note: this file originally auto-generated by mib2c using
 *        : mib2c.array-user.conf 15997 2007-03-25 22:28:35Z dts12 $
 *
 * $Id:$
 *
 * Yes, there is lots of code here that you might not use. But it is much
 * easier to remove code than to add it!
 */
#ifndef ZONEACCESSCLASSTABLE_H
#define ZONEACCESSCLASSTABLE_H

#ifdef __cplusplus
extern "C" {
#endif

    
#include <net-snmp/net-snmp-config.h>
#include <net-snmp/library/container.h>
#include <net-snmp/agent/table_array.h>

        /** Index zoneInstance is internal */
        /** Index zoneAccessClassInstance is internal */

typedef struct zoneAccessClassTable_context_s {
	netsnmp_index index; /** THIS MUST BE FIRST!!! */

	oid oid[2];

	struct dm_value_table *class;

} zoneAccessClassTable_context;

/*************************************************************
 * function declarations
 */
void init_zoneAccessClassTable(void);
void add_zoneAccessClassTable(struct dm_value_table *class);
void del_zoneAccessClassTable(struct dm_value_table *class);

#define zoneAccessClassTable_TABLE_OID 1,3,6,1,4,1,18681,1,1
    
/*************************************************************
 * column number definitions for table zoneAccessClassTable
 */
#define COLUMN_ZONEINSTANCE 1
#define COLUMN_ZONEACCESSCLASSINSTANCE 2
#define COLUMN_ZONEACCESSCLASSID 3
#define COLUMN_ZONEACCESSCLASSDESCR 4
#define COLUMN_ZONEACCESSCLASSCLIENTS 5
#define zoneAccessClassTable_COL_MIN 3
#define zoneAccessClassTable_COL_MAX 5

#ifdef __cplusplus
}
#endif

#endif /** ZONEACCESSCLASSTABLE_H */
