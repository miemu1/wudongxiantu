// This program is a part of NT MudLIB 
// Written by Lonely@nitan.org
// boots.c Ƥѥ
 
#include <ansi.h>
#include <armor.h>
 
inherit BOOTS;
 
void create()
{
        set_name(HIY "��" HIW "֮" HIM "ף��" NOR YEL "Ƥѥ"NOR, ({ "zhufu boots", "pi xue", "xue", "boots" }) );
        set_weight(200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "leather");
                set("unit", "˫");
                set("long", "����һ˫���Ϻ�ţƤ����Ƥѥ�����Ա����㲿��\n");
                set("value", 1000);
                set("armor_prop/dodge", 20);
        }

        set("auto_load", 1); 
        set("mod_mark", "A2014");  
        set("mod_level", "M2010");  
        set("mod_name", HIY"��"HIW"֮"HIM"ף��"NOR YEL"��װ"NOR); 

        set("enchase", ([ 
                "flute" : 1,
                "used" : 1,
                "apply_prop" : ([ /* sizeof() == 2 */
                        "armor1" : 30,
                        "dex" : 1,
                ]),
        ]));
        
        set("insert", ([ /* sizeof() == 1 */
                "1" : ([ /* sizeof() == 3 */
                        "id" : "magic stone",
                        "name" : HIM"��ʯ"NOR,
                        "apply_prop" : ([ /* sizeof() == 2 */
                                "armor1" : 30,
                                "dex" : 1,
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

