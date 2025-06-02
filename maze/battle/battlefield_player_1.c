
#include <ansi.h>
#include <buff.h>
#include <feature.h>

inherit CONDITION_MOD;

string id               = "battlefield_player_1";
string name     = HIW"��"NOR WHT"��"HIW"��"NOR WHT"ҫ"NOR;
string type     = CONDITION_TYPE_POSITIVE;
int time                = 86400;
int heartbeat   = 0;

// ����״̬ʱ��Ч��
void start_effect(object ob)
{
        ob->add(query_key()+"/"+BUFF_STR, 8);
        ob->add(query_key()+"/"+BUFF_PHY, 8);
        ob->add(query_key()+"/"+BUFF_INT, 8);
        ob->add(query_key()+"/"+BUFF_CHA, 8);
        ob->add(query_key()+"/"+BUFF_AGI, 8);
        ob->add(query_key()+"/"+BUFF_FOOD_MAX, 100);
        ob->add(query_key()+"/"+BUFF_DRINK_MAX, 100);
        ob->add(query_key()+"/"+BUFF_SOCIAL_EXP_BONUS, 15);
        ob->add(query_key()+"/"+BUFF_COMBAT_EXP_BONUS, 15);
        ob->add(query_key()+"/"+BUFF_STAMINA_MAX, 150);
        ob->add(query_key()+"/"+BUFF_HEALTH_MAX, 150);
        ob->add(query_key()+"/"+BUFF_ENERGY_MAX, 150);

        ::start_effect(ob);
}

// ����״̬ʱ��Ч��
void stop_effect(object ob)
{
        ::stop_effect(ob);
}

// ״̬�����е�Ч��
void heart_beat_effect(object ob)
{


}

int stackable()
{
        return 3;
}
