// This program is a part of NITAN MudLIB 
// redl 2013/3
#include <ansi.h>
inherit BAOXIANG_ITEM;

void create()
{
        set_name(HIC"��Ծ��"HIY"����"NOR,({"xiang"}));
        //���һ��Ҫ���ã�
        set("BAOXIANG_LIST",([
                                "/clone/money/gold"                                     :400,
                                "/clone/money/cash"                                     :50,
                "/clone/medicine/yuqing"                        :180,
                                "/clone/fam/gift/con2"                          :17,
                                "/clone/fam/gift/dex2"                          :17,
                                "/clone/fam/gift/int2"                          :17,
                                "/clone/fam/gift/str2"                          :17,
                                "/clone/fam/gift/con3"                          :12,
                                "/clone/fam/gift/dex3"                          :12,
                                "/clone/fam/gift/int3"                          :12,
                                "/clone/fam/gift/str3"                          :12,
                "/clone/fam/etc/prize5"                         :100,
                "/clone/gift/puti-zi"                           :58,
                                "/clone/tessera/rune01"                         :6,
                                "/clone/tessera/rune02"                         :6,
                                "/clone/tessera/rune03"                         :6,
                                "/clone/tessera/rune04"                         :6,
                                "/clone/tessera/rune05"                         :6,
                "/clone/gift/jiuzhuan"                          :37,
                                "/clone/tessera/rune10"                         :3,
                                "/clone/tessera/rune11"                         :3,
                                "/clone/tessera/rune12"                         :3,
                                "/clone/tessera/rune13"                         :3,
                                "/clone/tessera/rune14"                         :3,
                "/clone/gift/tianxiang"                         :9,
                                "/clone/goods/tianshi-charm"            :4,
                "/clone/gift/xuanhuang"                         :1,

                
        ])); //��������1000��Ϊ�������Ҽ���ĸ����ܺ�Ϊ1000�����ʴ�ĳ��ּ��ʸߡ�����
        
        set("long", HIY "����һֻ���������ӣ�װ�ε���ⱦ�����������Դ򿪣�open������\n" NOR); 
        set("unit", "Щ");
        set("base_unit", "��");
                set("dynamic_quest", 1);
                        set("no_give","�������������뿪�㡣\n");
                        set("no_drop","�������������뿪�㡣\n");
                set("no_sell", "�������������뿪�㡣\n");
                set("no_put", "�����������ܷ����Ƕ���\n");
                set("no_store", "�����������ܷ����Ƕ���\n");
                set("no_get", "�������������뿪�Ƕ���\n");
                set("no_steal", "�������������뿪�Ƕ���\n");
                set("no_beg", "�������������뿪�Ƕ���\n");
                set("base_value", 0);
                        set("base_weight",1);
        set_amount(1); //��Ϊ�Ǹ�combined��Ʒ �������һ��Ҫ���ã���Ȼ�����

}
void init()
{
        add_action("do_open","open"); //���ʹ�õĽӿ� ����������std��
        //add_action("do_test","test"); //������ʦ������ ����ok��ע�ʹ���
}

