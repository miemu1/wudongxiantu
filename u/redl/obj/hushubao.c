// This program is a part of NITAN MudLIB 
// redl 2014/3
#include <ansi.h>
inherit BAOXIANG_ITEM;

void create()
{
        set_name(NOR BLU"���汦"NOR,({"hushu bao", "bao"}));
        set("BAOXIANG_LIST",([
                                "/clone/money/thousand-gold"            :800,
                                "/clone/goods/tianshi-charm"            :130,
                                "/d/dongtian/obj/wanxiangbook"          :67,
                                "/u/redl/npc/obj/ntb"                   :3

        ])); //��������1000��Ϊ�������Ҽ���ĸ����ܺ�Ϊ1000�����ʴ�ĳ��ּ��ʸߡ�����
        
        set("long", NOR BLU "����Ů��ҹ��ר�ã�open����Ʒ����ͯЬ��ȥ�͵��͸��ݳ�������ɡ�\n" NOR); 
        set("unit", "Щ");
        set("base_unit", "��");
                set("dynamic_quest", 1);
                set("no_sell", "�������������뿪�㡣\n");
                set("no_store", "�����������ܷ����Ƕ���\n");
                set("no_steal", "�������������뿪�Ƕ���\n");
                set("no_beg", "�������������뿪�Ƕ���\n");
                set("base_value", 100);
                set("base_weight",1);
        set("bindable", 2); 
        set_amount(1); //��Ϊ�Ǹ�combined��Ʒ �������һ��Ҫ���ã���Ȼ�����

}

int cantuse()
{
        tell_object(this_player(), "��ڤ˼������ôҲ�ò���ǡ����ʹ�÷�����\n");
        return 1;
}

void init()
{
        if (query("gender",this_player())=="Ů��") {
                add_action("do_open","open"); //���ʹ�õĽӿ� ����������std��
        } else {
                add_action("cantuse","open"); //���ʹ�õĽӿ� ����������std��
        }
        //add_action("do_test","test"); //������ʦ������ ����ok��ע�ʹ���
}

