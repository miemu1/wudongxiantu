// This program is a part of NT MudLIB 
// Written by Lonely@nitan.org
 
#include <ansi.h>
#include <armor.h>
 
inherit SURCOAT;
 
void create()
{
        set_name(HIY "��" HIW "֮" HIM "ף��" NOR YEL "����" NOR, ({ "zhufu surcoat", "surcoat", "pi feng", "pifeng" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "˫");
                set("long", "����һ�����ʵ����硣\n"); 
                set("value", 1000); 
                set("material", "cloth");
                set("armor_prop/armor", 20);
        }
        
        set("auto_load", 1); 
        set("mark", "A2016");  
        set("mod_mark", "A2016");  
        set("mod_level", "M2010");  
        set("mod_name", HIY"��"HIW"֮"HIM"ף��"NOR YEL"��װ"NOR); 

        set("enchase", ([ 
                "flute" : 1,
                "used" : 1,
                "apply_prop" : ([ /* sizeof() == 2 */
                        "armor1" : 30,
                        "int" : 1,
                ]),
        ]));

        set("insert", ([ /* sizeof() == 1 */
                "1" : ([ /* sizeof() == 3 */
                        "id" : "magic stone",
                        "name" : HIM"��ʯ"NOR,
                        "apply_prop" : ([ /* sizeof() == 2 */
                                "armor1" : 30,
                                "int" : 1,
                        ]),
                ]),
        ]));
        
        set("require", ([
                "max_level" : 40,
                "max_age"   : 30,
        ]));
        set("quality_level", 2); 
        setup();
}

