#include <ansi.h>
#include <armor.h>
inherit SURCOAT;

void create()
{
        set_name(HIG "����������" NOR, ({ "wisdom surcoat", "surcoat", }));  

        if (clonep())
                set_default_object(__FILE__);
        else
        {
                set("long", "�̺��������ǵľ�Ԫ�������ǻ�(��)��\n"); 
                set("unit", "��");
                set("value", 2000000);
                set("material", "cloth");
                set("armor_prop/armor", 10);
        }
        set("auto_load", 1); 
        set("mod_mark", "A2001");  
        set("mod_level", "M2000");  
        set("mod_name", HBGRN"������ѧϰ��װ(��)"NOR); 
        set("enchase", ([ 
                "flute" : 2,
                "used"  : 2,
                "apply_prop" : ([ /* sizeof() == 4 */
                        "study_effect" : 10,
                        "int" : 8,
                        "derive_effect" : 10,
                        "armor1" : 30,
                ]),
        ]));

        set("insert", ([ /* sizeof() == 1 */
                "1" : ([ /* sizeof() == 3 */
                        "id" : "magic stone",
                        "name" : HIM"��ʯ"NOR,
                        "apply_prop" : ([ /* sizeof() == 2 */
                                "armor1" : 30,
                                "int" : 8,
                        ]),
                ]),
                "2" : ([ /* sizeof() == 3 */
                        "id" : "magic stone",
                        "name" : HIM"��ʯ"NOR,
                        "apply_prop" : ([ /* sizeof() == 2 */
                                "study_effect" : 10,
                                "derive_effect" : 10,
                        ]),
                ]),
        ]));
        
        set("quality_level", 2);  
       
        setup();
}
