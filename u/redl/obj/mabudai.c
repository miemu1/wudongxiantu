inherit ITEM;
void create()
{
        set_name("�鲼��", ({ "budai", "dai", "bag" })); 
        set_weight(0);
        set_max_encumbrance(100000000000000);
        /*if (clonep())
                set_default_object(__FILE__);
        else*/ {
                set("unit", "��");
                set("long", "һֻ���鲼֯�ɵĴ��ӣ��������װ������\n"); 
                set("value", 100);
                set("no_steal",1); 
        }
}

int is_container() { return 1; }

int no_limit_amount() { return 1; }
