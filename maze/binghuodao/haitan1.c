inherit ROOM;

#include <ansi.h>

void create()
{
        set("short", "��̲");
        set("long",
"�����Ǳ���������̲�������Ĵ��ź��߾�ʯ����Χ��һ����\n"
"�ʵĴ󺣣����ߴ�������޴�����죬�ض�ɽҡһ�㣬�ƺ����ϵ�\n"
"��ɽ�ڲ��ϵ��緢���ͷų��޴��������\n"
);
        set("exits", ([ 
                "south"    : __DIR__"shadi",
        ]));
        
        set("no_rideto", 1);         // ���ò������������ط�
        set("no_flyto", 1);          // ���ò��ܴ������ط�����������
        set("binghuo", 1);           // ��ʾ�ڱ���    
        set("outdoors", "battle4");
        
        set("objects", ([
        ]));
        
        set("no_fight", 1);
        
        setup();
}

