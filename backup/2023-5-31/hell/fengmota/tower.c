//Cracked by Roath
//����ɽ���ɡ�dhxy-evil 2000.7.5

inherit ROOM;                                                        
#include <ansi.h>                                                                     

void create ()                                                       
{                                                                    
  set ("short", HIG"��ħ��"NOR);                                   
  set ("long", @LONG                                                 
 �������Ƶ���������˵����װ���������֣��Ա���һʯ��(stone)��                                           
LONG);                                                          
        set("item_desc", ([
                "stone": @TEXT
��ħ����������ħ���������������

TEXT        ]) );
                                                                     
    set("exits", ([ /* sizeof() == 1 */                              
  "enter" : __DIR__"entrance",                                                                              
    "west" : "/d/shushan/jindi",
                                     
]));
set("objects",([
      CLASS_D("shushan/lxy") : 1,
    ]));                                                                 
 
  set("outdoors", "shushan");                                                                  
  setup();                                                           
}
