// This program is a part of NT MudLIB
// Written by Lonely@nitan.org
// equipmentd.c

#pragma optimize
#pragma save_binary

inherit F_DBASE;
#include <equipment.h>

#define EQUIP_DIR       "/inherit/template/"
#define EQUIP_LIST      CONFIG_DIR "equiplist/"

// ������ 2������Ϊ�����Ϳ��ֱ���(hand, finger)
// ������ head, armor, cloth, pants, boots, waist, wrists, surcoat 8��
// ��Ʒ�� charm, ring, neck 3��
// 7������7�ף�2������9�ף�3����Ʒ3��
/*

��Ů����С��Ů��������Ů�����书�˺�
���ӽ���С��Ů������ȫ�潣���书�˺�
�����ҩʦ���������｣���书�˺�
��⬼ף���ҩʦ�����ף���Ե��˿����˺�����ж�������˵���һ���˺�
��ң���ɻ��������ӣ�������������÷���书�˺�
���佣�������ᣩ����̫�����书�˺��������߱�������
�����񻷣�Ľ�ݲ������Ӳκ�ָ�书�˺�
���±�������쳣����ӵ��������书�˺�
������������쳣����ӵ��������书�˺�
�������ɶ򡢶ɽ١����ѣ��������±޷��书�˺�
�������ģ��ɽ٣����ף�������Ч�м�
��ݽᣨ���ѣ�ѥ�ӣ�������Ч�Ṧ
Ѫ����Ѫ�����棩����Ѫ�������书�˺�
���½��֣����ַ��������������ַ��书�˺�
�������ģ����ַ��������ף���ע��(force)����֮�������˺�
�����ȣ����߹������Ӵ򹷰����书�˺�
�����루�������ܣ����ӿ���ħ����а�����书�˺�
ʥ������޼ɣ�����ʥ����书�˺�

���پ������ӳ��еļ��� ������˫���˺����� ���Ǽ���30%�˺����ʡ����������������мܵļ��� ��ͨ��perform�˺��ӳ�
���� 5�п����� ���� ���� �񵲣������˺��� ��ͨ  ����
��ľˮ���������������ƣ�buff, ������ ����
�����ѣ�� ˮ������ʽ���� ���������˺����� ľ������ä

a ��������
����attack���̶���
�����˺��������
b  �������
������Ѫ���ԣ��̶���
���Ӷ�����Ѫ�ͻ��ף������
������Ѫ�ָ��������
c ħ������
����attack���̶���
����ħ���˺��������
d ħ������
���� ħ�����ԣ��̶���
���Ӷ�������;����������
f �������
�������˱������̶���
���ӷ����������������
���ӷ��� �����ָ��������
g ���ѷ�����ǿbuff
����buff ����ʱ�䣨�̶���
���Ӷ���Ⱥ�ˣ������
���Ӷ���Ⱥ���������
h �Թ����debuff
����buff ����ʱ�䣨�̶���
���ٹ��￹�ԣ������
*/

// ��������
mapping all_props = ([
        "consistence"   : "�;ö�",     // ��������
        "damage"        : "�����˺���", // ��������
        "unarmed_damage": "�����˺���", // ��������
        "armor"         : "������",     // ��������

        "str"           : "����",       // weapon/armor/rings \attribute.c
        "int"           : "����",       // weapon/armor/rings \attribute.c
        "con"           : "����",       // weapon/armor/rings \attribute.c
        "dex"           : "��",       // weapon/armor/rings \attribute.c
        "kar"           : "��Ե",       // weapon/armor/rings \attribute.c
        "per"           : "��ò",       // weapon/armor/rings \attribute.c

        "max_neili"     : "�������ֵ", // weapon/armor/rings \user.c
        "max_qi"        : "��Ѫ���ֵ", // weapon/armor/rings \user.c
        "max_jingli"    : "�������ֵ", // weapon/armor/rings \user.c
        "max_jing"      : "�������ֵ", // weapon/armor/rings \user.c
        "max_potential" : "Ǳ������",   // weapon/armor/rings \user.c
        "max_experience": "�������",   // weapon/armor/rings \user.c

        "sword"         : "����",       // weapon \combatd.c
        "blade"         : "����",       // weapon \combatd.c
        "club"          : "����",       // weapon \combatd.c
        "hammer"        : "����",       // weapon \combatd.c
        "staff"         : "�ȷ�",       // weapon \combatd.c
        "whip"          : "�޷�",       // weapon \combatd.c
        "unarmed"       : "ȭ��",       // weapon \combatd.c
        "strike"        : "�Ʒ�",       // weapon \combatd.c
        "cuff"          : "ȭ��",       // weapon \combatd.c
        "hand"          : "�ַ�",       // weapon \combatd.c
        "finger"        : "ָ��",       // weapon \combatd.c
        "claw"          : "צ��",       // weapon \combatd.c

        "attack"        : "����",       // weapon \combatd.c
        "parry"         : "�м�",       // armor  \combatd.c
        "dodge"         : "����",       // armor  \combatd.c
        "defense"       : "����",       // armor  \combatd.c

        "neili_recover" : "�����ָ�",   // armor/rings ս����ÿ��ָ� \char.c/damage.c
        "qi_recover"    : "�����ָ�",   // armor/rings ս����ÿ��ָ� \char.c/damage.c
        "jing_recover"  : "�����ָ�",   // armor/rings ս����ÿ��ָ� \char.c/damage.c

        // �����˺����䶳�˺��������˺��������˺������𣬿����������磬����
        "add_poison"    : "���˺�",     // weapon \itemd.c
        "add_magic"     : "ħ�˺�",     // weapon \itemd.c
        "add_metal"     : "���˺�",     // weapon \itemd.c
        "add_wood"      : "ľ�˺�",     // weapon \itemd.c
        "add_water"     : "ˮ�˺�",     // weapon \itemd.c
        "add_fire"      : "���˺�",     // weapon \itemd.c
        "add_earth"     : "���˺�",     // weapon \itemd.c
        "reduce_magic"  : "��ħ",       // armor  \itemd.c
        "reduce_metal"  : "����",       // armor  \itemd.c
        "reduce_wood"   : "��ľ",       // armor  \itemd.c
        "reduce_water"  : "��ˮ",       // armor  \itemd.c
        "reduce_fire"   : "����",       // armor  \itemd.c
        "reduce_earth"  : "����",       // armor  \itemd.c
        "reduce_poison" : "����",       // armor  \itemd.c/condition.c
        "avoid_poison"  : "�����ж�",   // armor/rings \itemd.c/condition.c

        "research_effect"       : "�о�Ч��",   // weapon/armor/rings \cmds
        "practice_effect"       : "��ϰЧ��",   // weapon/armor/rings \cmds
        "study_effect"          : "����Ч��",   // weapon/armor/rings \cmds
        "learn_effect"          : "ѧϰЧ��",   // weapon/armor/rings \cmds
        "derive_effect"         : "��ȡЧ��",   // weapon/armor/rings \cmds
        "research_times"        : "�о�����",   // weapon/armor/rings \cmds
        "learn_times"           : "ѧϰ����",   // weapon/armor/rings \cmds
        "practice_times"        : "��ϰ����",   // weapon/armor/rings \cmds
        "study_times"           : "�������",   // weapon/armor/rings \cmds
        "derive_times"          : "��ȡ����",   // weapon/armor/rings \cmds
        // ���϶��ǻ�������

        "magic_find"    : "Ѱ����(MFֵ)",       // weapon/rings \equipmentd.c

        "leech_neili"   : "͵ȡ����",           // weapon ����͵ȡ�������ʣ����е���ʱ���˺�ֵ��1%���ʻظ����� \damage.c/itemd.c
        "leech_qi"      : "͵ȡ����",           // weapon ����͵ȡ�������ʣ����е���ʱ���˺�ֵ��1%���ʻظ����� \damage.c/itemd.c
        "leech_jing"      : "͵ȡ����",           // weapon ����͵ȡ�����ʣ����е���ʱ���˺�ֵ��0.1%���ʻظ����� \damage.c/itemd.c
        "leech_jingli"      : "͵ȡ����",           // weapon ����͵ȡ�����ʣ����е���ʱ���˺�ֵ��0.1%���ʻظ����� \damage.c/itemd.c

        "ap_power"      : "���й�����",         // weapon/rings  \skillsd.c
        "dp_power"      : "���з�����",         // armor         \skillsd.c
        "da_power"      : "�����˺���",         // weapon/rings  \skillsd.c

        //"ignores_parry":
        "avoid_parry"   : "����Ŀ���м�",       // rune \combatd.c
        "avoid_dodge"   : "����Ŀ�����",       // rune \combatd.c
        "avoid_force"   : "�����ڹ�����",       // rune \combatd.c
        "avoid_attack"  : "����Ŀ���ع�",       // rune \combatd.c
        "avoid_defense" : "����Ŀ���ط�",       // rune \combatd.c

        //"critcal"       : "����",               // weapon/rings \combatd.c ����ɱ������һ��ɱ����������˫���˺����ĸ�������1%
        "through_armor" : "��͸�Ƽ�",           // weapon       \combatd.c ��͸�Ƽ�-����ʱ����Ŀ����ߵı�����through_armor

        "double_damage" : "˫���˺�",           // weapon/rings \combatd.c

        "qi_abs_neili"  : "��ת����",           // rings 30%�Ļ������������x%ת��Ϊ���� \damage.c

        "add_reward"    : "��ȡ���⽱��",       // weapon/rings \giftd.c
        /*
        "add_exp"       : "��ȡ������Ϊ",       // weapon/rings \giftd.c
        "add_pot"       : "��ȡ����Ǳ��",       // weapon/rings \giftd.c
        "add_mar"       : "��ȡ�������",       // weapon/rings \giftd.c
        */

        "add_blind"     : "��ä",                       // weapon �ռ����� ��ä-�ö���ʧ�� \damage.c/itemd.c
        "add_freeze"    : "����",                       // weapon �ռ����� ����-�ٻ��������Է�����������pfm�ٶȽ��ͣ����κη������޶��������мܣ����ǰ��� \damage/itemd.c/combatd.c/cmds
        "add_forget"    : "����",                       // weapon �ռ����� ����-ʹ�Է��������м��ܵľ���add_oblivion
        "add_weak"      : "����",                       // weapon �ռ�����
        "add_busy"      : "æ��",                       // weapon �ռ�����


        "avoid_blind"   : "������ä",                   // armor/rings �ռ�����
        "avoid_freeze"  : "���ӱ���",                   // armor/rings �ռ�����
        "avoid_forget"  : "��������",                   // armor/rings �ռ�����
        //add_oblivion

        "avoid_weak"    : "��������",                   // armor/rings �ռ�����
        "avoid_busy"    : "����æ��",                   // armor/rings �ռ�����
        "reduce_busy"   : "����æ��",                   // armor/rings �ռ�����
        "avoid_fear"    : "���ӿ־�",                   // armor/rings �ռ�����

        "fatal_blow"    : "����һ��",                   // weapon �ռ����� ��ɱ��-ӵ��20%�ļ�������Ŀ�������x%


        "add_skill"     : "��������",                   // weapon/rings �ռ�����
        "add_damage"    : "׷���˺�",                   // weapon �ռ�����
        "reduce_damage" : "�����˺�",                   // armor �ռ�����
        "full_self"     : "ս����",                   // armor �ռ����� ս����-��Ѫ�����Զ��ָ�  Զ��װ��
        "avoid_die"     : "ԡѪ����",                   // armor/ring ���������ԡѪ��������������   Զ��װ��
        "counter_damage": "�˺�����",                   // armor �ռ����� �˺����䣬�ܵ��˺�ʱ30%���ʵ��˺�x%������Է�
]);

mapping value_2_props = ([
        "consistence"   : "�;ö�",     // ��������           a
        "damage"        : "�����˺���", // ��������           a
        "unarmed_damage": "�����˺���", // ��������           a
        "armor"         : "������",     // ��������           a

        "str"           : "����",       // weapon/armor/rings a
        "int"           : "����",       // weapon/armor/rings a
        "con"           : "����",       // weapon/armor/rings a
        "dex"           : "��",       // weapon/armor/rings a
        "kar"           : "��Ե",       // weapon/armor/rings a
        "per"           : "��ò",       // rings              a

        "max_jingli"    : "�������ֵ", // weapon/armor/rings a
        "max_jing"      : "�������ֵ", // weapon/armor/rings a
        "max_potential" : "Ǳ������",   // weapon/armor/rings a
        "max_experience": "�������",   // weapon/armor/rings a

        "sword"         : "����",       // weapon             a
        "blade"         : "����",       // weapon             a
        "club"          : "����",       // weapon             a
        "hammer"        : "����",       // weapon             a
        "staff"         : "�ȷ�",       // weapon             a
        "whip"          : "�޷�",       // weapon             a
        "unarmed"       : "ȭ��",       // weapon             a
        "strike"        : "�Ʒ�",       // weapon             a
        "cuff"          : "ȭ��",       // weapon             a
        "hand"          : "�ַ�",       // weapon             a
        "finger"        : "ָ��",       // weapon             a
        "claw"          : "צ��",       // weapon             a

        "attack"        : "����",       // weapon             a
        "parry"         : "�м�",       // armor              a
        "dodge"         : "����",       // armor              a
        "defense"       : "����",       // armor              a

        "research_times": "�о�����",   // weapon/armor/rings a
        "learn_times"   : "ѧϰ����",   // weapon/armor/rings a
        "practice_times": "��ϰ����",   // weapon/armor/rings a
        "study_times"   : "�������",   // weapon/armor/rings a
]);

mapping value_3_props = ([
        "max_neili"     : "�������ֵ", // weapon/armor/rings b
        "max_qi"        : "��Ѫ���ֵ", // weapon/armor/rings b
        "neili_recover" : "�����ָ�",   // armor/rings        b
        "qi_recover"    : "�����ָ�",   // armor/rings        b
        "jing_recover"  : "�����ָ�",   // armor/rings        b

        "add_poison"    : "���˺�",     // weapon                           b
        "add_magic"     : "ħ�˺�",
        "add_metal"     : "���˺�",     // weapon                           b
        "add_wood"      : "ľ�˺�",     // weapon                           b
        "add_water"     : "ˮ�˺�",     // weapon                           b
        "add_fire"      : "���˺�",     // weapon                           b
        "add_earth"     : "���˺�",     // weapon                           b
        "reduce_magic"  : "��ħ",       // armor
        "reduce_metal"  : "����",       // armor                            b
        "reduce_wood"   : "��ľ",       // armor                            b
        "reduce_water"  : "��ˮ",       // armor                            b
        "reduce_fire"   : "����",       // armor                            b
        "reduce_earth"  : "����",       // armor                            b
        "reduce_poison" : "����",       // armor                            b
        "avoid_poison"  : "�����ж�",   // armor/rings                      b

        "research_effect"       : "�о�Ч��",   // weapon/armor/rings       b
        "practice_effect"       : "��ϰЧ��",   // weapon/armor/rings       b
        "study_effect"          : "����Ч��",   // weapon/armor/rings       b
        "learn_effect"          : "ѧϰЧ��",   // weapon/armor/rings       b
        "derive_effect"         : "��ȡЧ��",   // weapon/armor/rings       b
        "derive_times"          : "��ȡ����",   // weapon/armor/rings       b
]);

mapping value_5_props = ([
        "magic_find"    : "Ѱ����(MFֵ)",       // weapon/rings             c
        "ap_power"      : "���й�����",         // weapon/rings             c
        "dp_power"      : "���з�����",         // armor                    c
        "da_power"      : "�����˺���",         // weapon/rings             c
        "avoid_defense" : "��������Ŀ�����",   // weapon/rings             c
        "avoid_parry"   : "��������Ŀ���м�",   // weapon/rings             c
        "avoid_dodge"   : "��������Ŀ�����",   // weapon/rings             c
        "avoid_force"   : "���������ڹ�����",   // weapon/rings             c
        "avoid_attack"  : "����Ŀ�����⹥��",   // armor                    c
        "leech_neili"   : "͵ȡ����",           // weapon ����͵ȡ�������ʣ����е���ʱ���˺�ֵ��0.1%�ʻظ�����   c
        "leech_qi"      : "͵ȡ����",           // weapon ����͵ȡ�������ʣ����е���ʱ���˺�ֵ��0.1%���ʻظ����� c
        "double_damage" : "˫���˺�",           // weapon/rings ����ɱ������һ��ɱ����������˫���˺����ĸ�������1%  c
        "through_armor" : "��͸�Ƽ�",           // weapon/rings ��͸�Ƽ�-����ʱ����Ŀ����ߵı�����through_armor        c
        "qi_abs_neili"  : "��ת����",           // rings 30%�Ļ������������x%ת��Ϊ����  c

        "add_blind"     : "��ä",               // weapon �ռ����� ��ä-�ö���ʧ�� c
        "avoid_blind"   : "������ä",           // armor/rings �ռ�����            c
]);

mapping value_10_props = ([
        "add_freeze"    : "����",                       // weapon �ռ����� ����-�ٻ��������Է�����������pfm�ٶȽ��ͣ����κη������޶��������мܣ����ǰ��� d
        "add_forget"    : "����",                       // weapon �ռ����� ����-ʹ�Է��������м��ܵľ���add_oblivion    d
        "add_weak"      : "����",                       // weapon �ռ����� �ö��ֹ����˺����룬��������                 d
        "add_busy"      : "æ��",                       // weapon �ռ�����                                              d

        "avoid_freeze"  : "���ӱ���",                   // armor/rings �ռ����� d
        //"avoid_fear"    : "���ӿ־�",                   // armor/rings �ռ����� d
        "avoid_forget"  : "��������",                   // armor/rings �ռ����� d
        "avoid_weak"    : "��������",                   // armor/rings �ռ����� d
        "avoid_busy"    : "����æ��",                   // armor/rings �ռ����� d
        "reduce_busy"   : "����æ��",                   // armor/rings �ռ����� d

        "fatal_blow"    : "����һ��",                   // weapon �ռ����� ��ɱ��-ӵ��20%�ļ�������Ŀ�������x%     d                                    d
        "add_skill"     : "��������",                   // weapon/rings �ռ�����                                    d
        "add_damage"    : "׷���˺�",                   // weapon �ռ�����                                          d
        "reduce_damage" : "�����˺�",                   // armor �ռ�����                                           d
        "full_self"     : "ս����",                   // armor �ռ����� ս����-��Ѫ�����Զ��ָ�                 d
        "avoid_die"     : "ԡѪ����",                   // armor/ring ���������ԡѪ��������������                  d
        "counter_damage": "�˺�����",                   // armor �ռ����� �˺������ܵ��˺�ʱ30%���ʵ��˺�x%������Է� d
]);



// ��ʯ��Ϊ4���ȼ�����Ƭ�����1��ϡ��1+1����֮1+2
// һ���̶�������(��ľˮ����)+1-2���������

// �ٷֱȵ�����
string *percent_props = ({
        "gold_find", "magic_find", "add_magic", "add_metal", "add_wood", "add_water", "add_fire", "add_earth",
        "add_poison", "reduce_magic", "reduce_metal", "reduce_fire", "reduce_wood", "reduce_water", "reduce_earth",
        "reduce_poison", "avoid_poison", "research_effect", "learn_effect", "practice_effect",
        "derive_effect", "study_effect", "ap_power", "dp_power", "da_power", "avoid_attack",
        "avoid_defense", "avoid_parry", "avoid_dodge", "avoid_force", 
        "double_damage", "through_armor", "qi_abs_neili", "add_reward",
        "add_exp", "add_pot", "add_mar", "add_blind", "add_freeze",
        "add_forget", "add_weak", "avoid_blind", "avoid_freeze",
        "avoid_forget", "avoid_weak", "avoid_busy", "fatal_blow", 
        "add_damage", "reduce_damage", "full_self", "avoid_die", "counter_damage", "leech_neili", "leech_qi",
});

mapping prop_values = ([
        "damage"       : ({ 4600, 6600, 9600, 13600, 18600, 24600, 31600, 39600, 50000, }),
        "unarmed_damage"       : ({ 4600, 6600, 9600, 13600, 18600, 24600, 31600, 39600, 50000, }),
        "armor"        : ({ 2200, 2900, 3700, 4600, 5600, 7700, 8900, 10200, 11500, }),

        "str,con,dex,int,kar,per"     : ({ 1, 2, 3, }),         // 200

        "max_qi"        : ({ 2500, 3500, 4500, }),              // 200000
        "max_jing"      : ({ 1200, 1700, 2200, }),              // 100000
        "max_jingli"    : ({ 2500, 3500, 4500, }),              // 200000
        "max_neili"     : ({ 6000, 8000, 10000, }),             // 500000
        "max_potential,max_experience"  : ({ 30000, 40000, 50000, }),   // 2000000

        "attack,sword,blade,hammer,staff,club,whip,unarmed,strike,cuff,hand,finger,claw": ({ 10, 20, 30, }),        // 500
        "defense,parry,dodge"  : ({ 10, 20, 30, }),

        "jing_recover,qi_recover"       : ({ 20, 30, 40, }),    // 1000
        "neili_recover"     : ({ 60, 70, 80, }),
        "leech_qi,leech_neili"  : ({ 1.0, 1.5, 2.0, }),   // 1000

        "magic_find"    : ({ 1, 2, 3, }),       // 70

        "add_magic,add_metal,add_wood,add_water,add_fire,add_earth"    : ({ 1, 2, 3, }),       // 42
        "add_poison"    : ({ 1, 2, 3, }),       // 42
        "reduce_magic,reduce_metal,reduce_fire,reduce_wood,reduce_water,reduce_earth"     : ({ 1.0, 1.2, 1.5, }), // 35
        "reduce_poison,avoid_poison"    : ({ 1.0, 1.2, 1.5, }),       // 44

        "research_times,learn_times,practice_times,derive_times,study_times"    : ({ 5, 10, 15, }),    // 1000
        "research_effect,learn_effect,practice_effect,derive_effect,study_effect"       : ({ 1, 2, 3, }), // 180
        
        "ap_power,da_power"    : ({ 1.0, 1.5, 2.0, }),       // 70
        "dp_power"    : ({ 1.0, 1.2, 1.5, }),       // 70
        "avoid_attack,avoid_defense,avoid_parry,avoid_dodge,avoid_force": ({ 1.0, 1.2, 1.5, }),       // 70

        "double_damage,through_armor"   : ({ 1.0, 1.5, 2.0, }),       // 70
        "qi_abs_neili"   : ({ 1.0, 1.5, 2.0, }),       // 63

        "add_reward"    : ({ 1.0, 1.2, 1.5, }),       // 70
        "add_exp,add_pot,add_mar"     : ({ 1.0, 1.5, 2.0, }),       // 92

        "add_blind,fatal_blow"   : ({ 1.0, 1.5, 2.0 }),        // 42
        "avoid_blind" : ({ 1.0, 1.2, 1.5, }), // 44
        
        "add_skill"     : ({ 100, 130, 160, 200 }),
        "add_busy"      : ({ 6, 8, 10, 12 }),
        "reduce_busy"   : ({ 1, 2, 3, 4 }),
        "add_damage,add_freeze,add_forget,add_weak" : ({ 6, 8, 10, 12 }),
        "avoid_fear,avoid_forget,avoid_weak,avoid_busy,avoid_die,full_self,counter_damage,reduce_damage": ({ 1, 2, 3, 4 }),
]);

// ����ǿ��ֵ1-9��
mapping steady_values = ([
        "damage,unarmed_damage"       : ({ 4600,6600,9600,13600,18600,24600,31600,39600,50000 }),
        "armor"         : ({ 2200,2900,3700,4600,5600,7700,8900,10200,11500 }),

        "str,con,dex,int"     : ({ 5, 7, 9, 11, 14, 17, 20, 25, 30, }),

        "max_qi"        : ({ 1000, 2000, 3000, 5000, 7000, 9000, 12000, 15000, 20000, }),
        "max_jing"      : ({ 500, 1000, 1500, 2500, 3500, 4500, 6000, 7500, 10000, }),
        "max_jingli"    : ({ 1000, 2000, 3000, 5000, 7000, 9000, 12000, 15000, 20000, }),
        "max_neili"     : ({ 10000, 20000, 30000, 40000, 50000, 60000, 70000, 80000, 100000, }),
        "max_potential,max_experience"  : ({ 200000, 400000, 600000, 1000000, 1500000, 2000000, 3000000, 4000000, 6000000, }),

        "attack,sword,blade,hammer,staff,club,whip,unarmed,strike,cuff,hand,finger,claw": ({ 20, 30, 40, 60, 80, 110, 150, 200 }),
        "dodge,parry,defense"   : ({ 10, 15, 20, 25, 30, 35, 40, 45, 60 }),

        "jing_recover,qi_recover"       : ({ 60, 70, 80, 100, 120, 140, 160, 180, 200, }),
        "neili_recover"     : ({ 120, 140, 160, 180, 240, 280, 320, 360, 500, }),
        "leech_qi,leech_neili"  : ({ 1, 2, 3, 4, 5, 6, 7, 8, 10, }),

        "magic_find"    : ({ 1, 2, 3, 5, 7, 9, 11, 13, 15, }),

        "add_poison,add_magic,add_metal,add_wood,add_water,add_fire,add_earth"    : ({ 3, 5, 7, 10, 13, 16, 19, 23, 28, }),
        "reduce_poison,avoid_poison,reduce_magic,reduce_metal,reduce_fire,reduce_wood,reduce_water,reduce_earth"     : ({ 1, 2, 3, 4, 5, 6, 7, 8, 9, }),

        "research_times,learn_times,practice_times,derive_times,study_times"    : ({ 10, 15, 20, 25, 30, 35, 40, 45, 50 }),
        "research_effect,learn_effect,practice_effect,derive_effect,study_effect"       : ({ 5, 7, 9, 12, 15, 18, 21, 25, 30, }),

        "ap_power,da_power"    : ({ 1, 2, 3, 4, 5, 6, 7, 8, 10, }),
        "dp_power"      : ({ 1, 1.5, 2, 2.5, 3, 3.5, 4, 4.5, 5, }),
        "avoid_defense,avoid_parry,avoid_dodge,avoid_force": ({ 1, 2, 3, 4, 5, 6, 7, 8, 10, }),
        "avoid_attack"  : ({ 1, 1.5, 2, 2.5, 3, 3.5, 4, 4.5, 5, }),

        "double_damage,through_armor"   :  ({ 1, 2, 3, 4, 5, 6, 7, 8, 10, }),
        "qi_abs_neili"   : ({ 1, 2, 3, 4, 5, 6, 7, 8, 10, }),

        "add_reward"    : ({ 1, 2, 3, 4, 5, 6, 7, 8, 10, }),
        "add_exp,add_pot,add_mar,add_force"  :  ({ 1, 2, 3, 5, 7, 9, 11, 13, 15, }),

        "add_blind,avoid_blind"   : ({ 1, 2, 3, 4, 5, 6, 7, 8, 10, }),
        
        "add_freeze,add_forget,add_weak,avoid_freeze,avoid_forget,avoid_weak,avoid_busy" : ({ 1, 1.5, 2, 2.5, 3, 3.5, 4, 4.5, 5, }),
        "add_busy,reduce_busy"   : ({ 1, 2, 3, 4, 5, 6, 7, 8, 10, }),
        "fatal_blow"    : ({ 1, 1.5, 2, 2.5, 3, 3.5, 4, 4.5, 5, }),
        "add_skill"     : ({ 10, 15, 20, 25, 30, 35, 40, 45, 50, }),
        "add_damage"    : ({ 1, 2, 3, 4, 5, 6, 7, 8, 10, }),
        "reduce_damage" : ({ 1, 1.5, 2, 2.5, 3, 3.5, 4, 4.5, 5, }),
        "full_self"     : ({ 1, 1.5, 2, 2.5, 3, 3.5, 4, 4.5, 5, }),
        "avoid_die"     : ({ 1, 1.5, 2, 2.5, 3, 3.5, 4, 4.5, 5, }),
        "counter_damage": ({ 1, 1.5, 2, 2.5, 3, 3.5, 4, 4.5, 5, }),
]);

// װ����Ʒ����6����ǰ2��Ʒ������û�����⣬��ϡ�У���������Ʒ����ʼ����������
// ��ʯ�ĵȼ���3������ʯ������Ӧ�ú�װ��ǰ2��Ʒ��������һ��
// qlvl1ֻ�л������ԣ�qlvl2���б�ʯ���ԣ�qlvl3ӵ�б�ʯ���ԣ�qlvl4ӵ��ʷʫ���ԣ�qlvl5ӵ�д�˵���ԣ�qlvl6ӵ����������
mixed weapon_props = ({
        ({ "damage", "int", "str", "con", "dex", "kar", "skill", "attack",
           "magic_find", "add_poison",
           "research_times", "learn_times", "practice_times", "derive_times",
           "study_times", "research_effect", "learn_effect", "practice_effect",
           "derive_effect", "study_effect", "ap_power", "da_power", "avoid_defense",
           "avoid_parry", "avoid_dodge", "avoid_force", "double_damage",
           "through_armor", 
           "add_blind", 
           "max_neili", "max_qi", "max_jing", "max_jingli", "max_potential", "max_experience",
        }),
        ({ "research_effect", "practice_effect", "study_effect", "learn_effect", "derive_effect", 
           "attack", "ap_power", "da_power", "avoid_defense", "avoid_parry", "avoid_dodge",
           "avoid_force", "through_armor", "skill", // skill���⴦��
           "leech_qi", "leech_neili",
        }),
        ({ "through_armor", "double_damage", 
           "add_blind", 
           "research_effect", "practice_effect", "derive_effect", 
           "ap_power", "da_power",
           "leech_qi", "leech_neili", "add_damage", "add_busy", "add_freeze", "add_weak", 
        }),
        ({ "add_blind", "double_damage", "research_effect", "practice_effect", "derive_effect", 
           "ap_power", "da_power",
           "add_freeze", "add_weak", "add_forget", "add_busy", "fatal_blow", "add_damage",
        }),
});

mixed armor_props = ({
        ({ "armor", "int", "str", "con", "dex", "kar", "max_neili", "max_qi", "max_jing",
           "max_jingli", "max_potential", "max_experience", "parry", "dodge", "defense",
           "neili_recover", "jing_recover", "qi_recover", "reduce_poison", "avoid_poison", "research_times",
           "learn_times", "practice_times", "derive_times", "study_times", "research_effect",
           "learn_effect", "practice_effect", "derive_effect", "study_effect", "dp_power", "avoid_attack",
           "avoid_blind",
        }),
        ({ "research_effect", "practice_effect", "study_effect", "learn_effect", "derive_effect",
           "reduce_poison", "avoid_poison", "max_qi", "max_jing", "parry", "dodge", "defense", 
        }),
        ({ "neili_recover", "jing_recover", "qi_recover", "avoid_attack", "dp_power", "avoid_blind",
           "research_effect", "practice_effect", "derive_effect", 
           "counter_damage", "reduce_busy", "reduce_damage", "avoid_freeze", "avoid_weak",
        }),
        ({ "avoid_blind", "research_effect",
           "dp_power", "research_effect", "practice_effect", "derive_effect", 
           "avoid_freeze", "avoid_forget", "avoid_weak", "avoid_busy", "reduce_busy", "reduce_damage", "full_self", "avoid_die", "counter_damage",
        }),
});

// ����amulet����ָring�����������charm
mixed ring_props = ({
        ({ "per", "max_neili", "max_qi", "max_jing", "max_jingli", "max_potential",
           "max_experience", "neili_recover", "jing_recover", "qi_recover",
           "magic_find", "avoid_poison", "research_times", "learn_times", "practice_times", "derive_times",
           "study_times", "research_effect", "learn_effect", "practice_effect", "derive_effect", "study_effect",
           "ap_power", "da_power", "avoid_defense", "avoid_parry", "avoid_dodge", "avoid_force",
           "double_damage", "through_armor", "qi_abs_neili",
           "avoid_blind", 
           "through_armor", 
        }),
        ({ "research_effect", "practice_effect", "study_effect", "learn_effect", "derive_effect",
           "reduce_poison", "avoid_poison", "max_qi", "max_jing",
        }),
        ({ "through_armor", "magic_find", "qi_abs_neili", "research_effect", "practice_effect", "derive_effect",
           "ap_power", "da_power", "avoid_defense", "avoid_parry", "avoid_dodge", "avoid_force", 
           "reduce_busy", "avoid_freeze", "avoid_weak",
        }),
        ({ "avoid_blind", "research_effect", "practice_effect", "derive_effect", 
           "magic_find", "double_damage",
           "avoid_freeze", "avoid_forget", "avoid_weak", "avoid_die", "avoid_busy", "reduce_busy",
        }),
});

string *rare_props = ({
        "avoid_freeze", "avoid_forget", "avoid_weak", "avoid_busy", "reduce_busy", "reduce_damage", "full_self", "avoid_die", "counter_damage",
        "add_freeze", "add_weak", "add_forget", "add_busy", "fatal_blow", "add_damage",
});
        
// �׻��ı�������
string *suit_weapon_props = ({
        "double_damage", "avoid_forget", "add_damage", "add_skill", "fatal_blow", "add_busy", "add_weak",
        "add_freeze",

});
// �׻��ķ�������
string *suit_armor_props = ({
        "reduce_busy", "avoid_busy", "avoid_weak", "avoid_die",
        "counter_damage", "avoid_forget", "full_self", "reduce_damage", "research_effect",
});
// �׻��Ļ��������
string *suit_ring_props = ({
        "magic_find", "avoid_die",
        "full_self", "avoid_busy", "avoid_forget", "research_effect",
});

void create()
{
        seteuid(getuid());
        set("name", "װ������");
        set("id", "equipmentd");
}

// Ϊ��������ƥ������
varargs string chinese(string prop, mixed value)
{
        string desc;

        if( !undefinedp(all_props[prop]) )
                desc = all_props[prop];
        else
                desc = to_chinese(prop);

        if( !value ) return desc;

        if( member_array(prop, percent_props) != -1 )
        {
                if( floatp(value) )
                desc = sprintf("%s %s%.1f%s", desc,
                               value > 0 ? "+" : "-", abs(value), "%");
                else
                desc = sprintf("%s %s%d%s", desc,
                               value > 0 ? "+" : "-", abs(value), "%");
        }
        else
        {
                if( floatp(value) )
                desc = sprintf("%s %s%.1f", desc,
                               value > 0 ? "+" : "-", abs(value));
                else
                desc = sprintf("%s %s%d", desc,
                               value > 0 ? "+" : "-", abs(value));
        }

        return desc;
}

// ��ȡװ������������
varargs mixed query_prop_value(string prop, int ilvl, int s)
{
        int i, j, flag;
        int *value;
        float n;
        mapping data;
        string *ks;
        string *temp_str;

        flag = 0;
        if( s ) data = copy(steady_values); // ǿ������
        else data = copy(prop_values);
        ks = keys(data);
        for( i=0; i<sizeof(ks); i++ ) {
                //reset_eval_cost();
                temp_str = explode(ks[i], ",");
                for( j=0; j<sizeof(temp_str); j++ )
                        if( temp_str[j] == prop ) {
                                value = data[ks[i]];
                                flag = 1;
                                break;
                        }
                if( flag ) break;
        }
        if( !flag || !value ) return 0;
        if( ilvl ) {
                if( ilvl > sizeof(value) )
                        ilvl = sizeof(value);
                
                if( member_array(prop, rare_props) == -1 )
                        return value[ilvl-1];
                
                n = 1.0 + (ilvl-1)*0.5;
                return n;
        }
        return value[random(sizeof(value))];
}

// װ���̻�ʱ���õ�����
mapping apply_ultimate_prop(object ob, string type, int ilvl)
{
        string *props;
        string prop;
        mapping apply;
        mixed value;
        int n;

        apply = ([]);

        if( type == "weapon"
        ||  type == "sword"
        ||  type == "xsword"
        ||  type == "blade"
        ||  type == "whip"
        ||  type == "hammer"
        ||  type == "staff"
        ||  type == "club"
        ||  type == "throwing"
        ||  type == "hands"
        ||  type == "finger" )
                props = suit_weapon_props;
        else
        if( type == "rings"
        ||  type == "charm"
        ||  type == "myheart"   // ���������
        ||  type == "myheart2"  // ���������
        ||  type == "neck" )
                props = suit_ring_props;
        else
                props = suit_armor_props;

        n = 1;
        if( random(10000) == 1 )
                n = 2;
        while( n > 0 )
        {
                prop = props[random(sizeof(props))];
                props -= ({ prop });

                value = query_prop_value(prop, ilvl, 1);
                apply[prop] = value;

                n--;
        }
        return apply;
}

// ���ɱ�ʯ����
varargs mapping apply_gem_prop(string type, int ilvl, int special, int n)
{
        string *props;
        string prop;
        mapping apply;
        mixed value;

        apply = ([]);

        if( type == "weapon"
        ||  type == "sword"
        ||  type == "xsword"
        ||  type == "blade"
        ||  type == "whip"
        ||  type == "hammer"
        ||  type == "staff"
        ||  type == "club"
        ||  type == "throwing"
        ||  type == "hands"
        ||  type == "finger" ) {
                if( special )
                        props = weapon_props[3];
                else
                        props = weapon_props[0]; // ��ȡ��Ӧ��Ʒ������
        }
        else
        if( type == "rings"
        ||  type == "charm"
        ||  type == "myheart"   // ���������
        ||  type == "myheart2"  // ���������
        ||  type == "neck" ) {
                if( special )
                        props = ring_props[3];
                else
                        props = ring_props[0];
        }
        else
        {
                if( special )
                        props = armor_props[3];
                else
                        props = armor_props[0];
        }

        if( type == "weapon" ) props -= ({ "skill" });
        
        if( special ) n = 3;
        if( !n ) n = 1 + random(3);

        while( n > 0 )
        {
                prop = props[random(sizeof(props))];
                props -= ({ prop });

                if( prop == "skill" ) // skill�������
                {
                        int rate;
                        rate = random(100);
                        if( type == "finger" )
                        {
                                if( rate < 50 )
                                        prop = "claw";
                                else
                                        prop = "finger";
                        } else
                        if( type == "hands" )
                        {
                                if( rate < 25 )
                                        prop = "unarmed";
                                else if( rate < 50 )
                                        prop = "cuff";
                                else if( rate < 75 )
                                        prop = "hand";
                                else
                                        prop = "strike";
                        } else
                                prop = type;
                }
                value = query_prop_value(prop, ilvl);
                apply[prop] = value;

                n--;
        }
        return apply;
}

// ����װ������
mapping apply_props(string type, int ilvl, int n, int special)
{
        mapping applied_prop;
        mapping enchase_prop;
        mapping data = ([]);
        string *apply;
        mapping *insert;
        int i, j;

        applied_prop = ([]);
        insert = ({});

        if( !n ) return data;
        for( i=1; i<=n; i++ ) // ������
        {
                enchase_prop = copy(apply_gem_prop(type, ilvl, special));
                apply = keys(enchase_prop);
                for( j=0; j<sizeof(apply); j++ )
                {
                        if( !sizeof(applied_prop) || undefinedp(applied_prop[apply[j]]) )
                                applied_prop[apply[j]] = enchase_prop[apply[j]];
                        else
                                applied_prop[apply[j]] += enchase_prop[apply[j]];
                }
                insert += ({ (["name" : HIM"��ʯ"NOR, "id" : "magic stone", "apply_prop" : enchase_prop]) });
        }

        data["apply_prop"] = applied_prop;
        data["insert"] = insert;
        return data;
}

protected mapping trans_data(string mark)
{
        int     i;
        mixed   temp_value;
        string  temp_str, temp_str2;
        string *temp_arr, *temp_val;
        string  temp_key, key;
        mapping temp_status;
        mapping temp_map;
        mapping *temp_map2;

        temp_status = ([ ]);

        // ����insert
        if( sscanf(mark, "%s<insert>%s</insert>", mark, temp_str2) == 2 )
        {
                temp_map2 = ({ });
                while (sscanf(temp_str2, "%*s[%s]%s[/%s]%s", key, temp_str, key, temp_str2) > 3)
                {
                        temp_map = ([ ]);
                        temp_arr = explode(temp_str, "\n");

                        for ( i=0; i<sizeof(temp_arr); i++ ) {
                                //temp_arr[i] = replace_string(temp_arr[i], " ", "");
                                if( sscanf(temp_arr[i], "%s:%d", temp_key, temp_value) != 2 )
                                        sscanf(temp_arr[i], "%s:%s", temp_key, temp_value);

                                // ����VALUE
                                if( stringp(temp_value) && strsrch(temp_value, '/') != -1 ) {
                                        temp_val = explode(temp_value, "/");
                                        temp_value = ({});
                                        for (i = 0; i <sizeof(temp_val); i++)
                                                if( atoi(temp_val[i]) )
                                                        temp_value += atoi(temp_val[i]);
                                                else
                                                        temp_value += temp_val[i];
                                }
                                // ����KEY
                                if( stringp(temp_key) && strsrch(temp_key, '/') != -1 )
                                        _set( temp_map, explode(temp_key, "/"), temp_value );
                                else
                                        temp_map[temp_key] = temp_value;

                                if( !undefinedp(temp_map["name"]) )
                                        temp_map["name"] = trans_color(temp_map["name"], 3);
                        }
                        temp_map2 += ({ temp_map });
                }
                temp_status["insert"] = temp_map2;
        }

        // ��ʼ����
        while (sscanf(mark, "%*s<%s>%s</%s>%s", key, temp_str, key, mark) > 3)
        {
                temp_map = ([ ]);
                temp_arr = explode(temp_str, "\n");
                if( sizeof(temp_arr) < 2 ) {
                        if( sscanf(temp_arr[0], "%s:%d", temp_key, temp_value) == 2 ||
                            sscanf(temp_arr[0], "%s:%s", temp_key, temp_value) == 2 ) {
                               // ����VALUE
                                if( stringp(temp_value) && strsrch(temp_value, '/') != -1 ) {
                                        temp_val = explode(temp_value, "/");
                                        temp_value = ({});
                                        for (i = 0; i <sizeof(temp_val); i++)
                                                if( atoi(temp_val[i]) )
                                                        temp_value += atoi(temp_val[i]);
                                                else
                                                        temp_value += temp_val[i];
                                }
                                // ����KEY
                                if( stringp(temp_key) && strsrch(temp_key, '/') != -1 )
                                        _set( temp_map, explode(temp_key, "/"), temp_value );
                                else
                                        temp_map[temp_key] = temp_value;

                                temp_status[key] = temp_map;
                        }
                        else if( atoi(temp_str) )
                                temp_status[key] = atoi(temp_str);
                        else
                                temp_status[key] = temp_str;

                } else {
                        for ( i=0; i<sizeof(temp_arr); i++ ) {
                                temp_arr[i] = replace_string(temp_arr[i], " ", "");
                                if( sscanf(temp_arr[i], "%s:%d", temp_key, temp_value) != 2 )
                                        sscanf(temp_arr[i], "%s:%s", temp_key, temp_value);

                                // ����VALUE
                                if( stringp(temp_value) && strsrch(temp_value, '/') != -1 ) {
                                        temp_val = explode(temp_value, "/");
                                        temp_value = ({});
                                        for (i = 0; i <sizeof(temp_val); i++)
                                                if( atoi(temp_val[i]) )
                                                        temp_value += atoi(temp_val[i]);
                                                else
                                                        temp_value += temp_val[i];
                                }
                                // ����KEY
                                if( stringp(temp_key) && strsrch(temp_key, '/') != -1 )
                                        _set( temp_map, explode(temp_key, "/"), temp_value );
                                else
                                        temp_map[temp_key] = temp_value;
                        }
                        temp_status[key] = temp_map;
                }
        }

        if( !undefinedp(temp_status["name"]) )
                temp_status["name"] = trans_color(temp_status["name"], 3);

        if( !undefinedp(temp_status["mod_name"]) )
                temp_status["mod_name"] = trans_color(temp_status["mod_name"], 3);

        if( !undefinedp(temp_status["long"]) )
                temp_status["long"] = trans_color(temp_status["long"], 3) + "\n";

        return temp_status;
}

// ����һ���̶�������������
varargs mixed create_object(string num, int level)
{
        string *list;
        string  mark, part, rec;
        string  type, str;
        string  filename, this_file;
        mapping temp_status;
        mapping temp_function;
        object  ob;

        if( !num || num == "" ) {
                if( !level ) level = random(3);

                switch( random(3) )
                {
                case 0 :
                        rec = "W";
                        if( level == 0) filename = EQUIP_LIST+"basic.weapon";
                        else if( level == 1) filename = EQUIP_LIST+"advance.weapon";
                        else if( level == 2) filename = EQUIP_LIST+"expert.weapon";
                        break;
                case 1 :
                        rec = "A";
                        if( level == 0) filename = EQUIP_LIST+"basic.armor";
                        else if( level == 1) filename = EQUIP_LIST+"advance.armor";
                        else if( level == 2) filename = EQUIP_LIST+"expert.armor";
                        break;
                default:
                        rec = "G";
                        if( level == 0) filename = EQUIP_LIST+"basic.gem";
                        else if( level == 1) filename = EQUIP_LIST+"advance.gem";
                        else if( level == 2) filename = EQUIP_LIST+"expert.gem";
                        break;
                }

                this_file = read_file(filename);
                str = sprintf("%s%d", rec, level);
                list = ({});
                while (sscanf(this_file, "%*s<"+str+part+">%*s</"+str+part+">%*s"))
                {
                        rec = sprintf("%s%s", str, part);
                        list += ({ rec });
                }
                if( !sizeof(list) ) return 0;
                num = list[random(sizeof(list))];
        } else {
                if( num[0] == 'W' ) {
                        if( num[1] == '0' && strlen(num) == 5 )
                                filename = EQUIP_LIST+"basic.weapon";
                        else if( num[1] == '1' && strlen(num) == 5 )
                                filename = EQUIP_LIST+"advance.weapon";
                        else if( num[1] == '2' && strlen(num) == 5 )
                                filename = EQUIP_LIST+"expert.weapon";
                } else if( num[0] == 'A' ) {
                        if( num[1] == '0' && strlen(num) == 5)
                                filename = EQUIP_LIST+"basic.armor";
                        else if(  num[1] == '1' && strlen(num) == 5)
                                filename = EQUIP_LIST+"advance.armor";
                        else if(  num[1] == '2' && strlen(num) == 5)
                                filename = EQUIP_LIST+"expert.armor";
                } else if( num[0] == 'G' ) {
                        if(  num[1] == '0' && strlen(num) == 5)
                                filename = EQUIP_LIST+"basic.gen";
                        else if(  num[1] == '1' && strlen(num) == 5)
                                filename = EQUIP_LIST+"advance.gen";
                        else if(  num[1] == '2' && strlen(num) == 5)
                                filename = EQUIP_LIST+"expert.gen";
                }

                if( !filename )
                        return 0;

                this_file = read_file(filename);
        }

        // ������Ŷ�Ӧ���ַ���
        if( sscanf(this_file, "%*s<"+num+">%s</"+num+">%*s", mark) ) {
                sscanf(mark, "%*s<type>%s</type>%s", type, mark);
                filename = EQUIP_DIR + type;
                temp_status = trans_data(mark);
                temp_function = temp_status["function"];
                if( temp_function )
                        map_delete(temp_status, "function");
                else
                        temp_function = allocate_mapping(0);

                ob = TEMPLATE_D->create_object(filename, temp_status["id"], temp_status, 0, temp_function);
                set("mod_mark", num, ob);
                set("can_sign", 1, ob); // װ��ǩ��
                if( temp_status["mod_level"] )
                        set("mod_level", temp_status["mod_level"], ob);

                return ob;
        } else {
                CHANNEL_D->do_channel(this_object(),"sys", "����һ������������");
                return 0;
        }
}

// ����һ���̶���װ�������������
varargs object create_module(string num, int level)
{
        string mark, part, str, rec;
        string *list;
        string type;
        string filename, this_file;
        mapping temp_status;
        mapping temp_function;
        object ob;

        if( !num || num == "" ) {
                if( !level ) level = random(4);

                if( level == 0 ) filename = EQUIP_LIST+"basic.mod";
                else if( level == 1 ) filename = EQUIP_LIST+"advance.mod";
                else if( level == 2 ) filename = EQUIP_LIST+"expert.mod";
                else if( level == 3 ) filename = EQUIP_LIST+"boss.mod";

                this_file = read_file(filename);
                str = sprintf("A%d", level);
                list = ({});
                while (sscanf(this_file, "%*s<"+str+part+">%*s</"+str+part+">%*s"))
                {
                        rec = sprintf("%s%s", str, part);
                        list += ({ rec });
                }
                if( !sizeof(list) ) return 0;
                num = list[random(sizeof(list))];
        } else {
                if(  num[1] == '0' && strlen(num) == 5 )
                        filename = EQUIP_LIST+"basic.mod";
                else if(  num[1] == '1' && strlen(num) == 5 )
                        filename = EQUIP_LIST+"advance.mod";
                else if(  num[1] == '2' && strlen(num) == 5 )
                        filename = EQUIP_LIST+"expert.mod";
                else if(  num[1] == '3' && strlen(num) == 5 )
                        filename = EQUIP_LIST+"boss.mod";

                this_file = read_file(filename);
        }
        //������Ŷ�Ӧ���ַ���
        if( sscanf(this_file, "%*s<"+num+">%s</"+num+">%*s", mark) )
        {
                sscanf(mark, "%*s<type>%s</type>%s", type, mark);
                filename = EQUIP_DIR + type;
                temp_status = trans_data(mark);
                temp_function = temp_status["function"];
                if( temp_function )
                        map_delete(temp_status, "function");
                else
                        temp_function = allocate_mapping(0);

                ob = TEMPLATE_D->create_object(filename, temp_status["id"], temp_status, 0, temp_function);
                set("mod_mark", num, ob);
                //set("can_sign", 1, ob); // װ��ǩ��
                //if( temp_status["mod_level"] )
                //        set("mod_level", temp_status["mod_level"], ob);

                return ob;
        } else {
                CHANNEL_D->do_channel(this_object(), "sys", "����һ����װ��������");
                return 0;
        }
}

// ����һ����̬�����
public varargs object create_dynamic(string obj_type, int ilvl, int mf, int flag)
{
        mapping temp_status, all_list, data;
        mapping applied_prop = ([]);
        mapping *insert;
        string *gems1 = ({ "cruby", "ctopaz", "csapphire", "cemerald", "cdiamond" });
        string *gems2 = ({ "ruby", "topaz", "sapphire", "emerald", "diamond" });
        string *gems3 = ({ "xruby", "xtopaz", "xsapphire", "xemerald", "xdiamond" });
        string *gems4 = ({ "fruby", "ftopaz", "fsapphire", "femerald", "fdiamond" });
        string *gems5 = ({ "mruby", "mtopaz", "msapphire", "memerald", "mdiamond" });
        string *all_id, *types;
        string id;
        string *file;
        string color, filename;
        string base_type;
        object ob;
        int qlvl;
        int rate, rate2, n, uf, sf, rf;
        string prop, *props;

        if( !ilvl || ilvl < 1 )
                return 0;

        if( !obj_type || obj_type == "" ) { // �������װ�������ʯ
                rate = random(100);
                if( rate < 35 ) obj_type = "weapon";
                else if( rate < 90 ) obj_type = "armor";
                //��ʱȡ����Ʒ�ĵ���
                //else if( rate < 90 ) obj_type = "rings";
                else obj_type = "gem";
                flag = 0;
        }

        if( flag ) { // ָ���ı������͡��������ͻ�ʯ����
                if( flag == 1 ) {
                        if( member_array(obj_type, weapon_type) != -1 )
                                base_type = "weapon";
                        else if( member_array(obj_type, armor_type) != -1 )
                                base_type = "armor";
                        else if( member_array(obj_type, rings_type) != -1 )
                                base_type = "rings";
                        else    base_type = "gem";
                } else {
                        // ϵͳ�̶������ƺ�ID��װ��
                        all_list = type_list[obj_type];
                        all_id = values(all_list);
                        id = all_id[random(sizeof(all_id))];
                }
        } else {
                base_type = obj_type;
                types = all_type[obj_type];
                obj_type = types[random(sizeof(types))]; // ���һ��
        }

        if( flag && flag > 1 ) // ��ģ���ļ�����Ҫ���д��
                filename = sprintf("%s%s/%s.c", TEMPLATE_DIR, base_type, obj_type);
        else
                filename = sprintf("%s%s/%s.c", EQUIP_DIR, base_type, obj_type);

        data = ([]);
        temp_status = ([]);
        /*
        rate = random(100);
        if( rate < 40 ) data["str"] = ilvl*2 + random(ilvl);
        else if( rate < 60 ) data["con"] = ilvl*2 + random(ilvl);
        else if( rate < 80 ) data["dex"] = ilvl*2 + random(ilvl);
        else data["int"] = ilvl*2 + random(ilvl);

        data["level"] = ilvl;
        temp_status["require"] = copy(data); // ����װ��Ҫ��
        */

        if( base_type != "gem" ) // ����װ�����Ǳ�ʯ
        {
                // ������������ͨ0������1����ϡ2��ʷʫ3����˵4������5
                // ����6�ף�����4�ף������3�ף�����4��
                
                data = ([]);
                
                if( mf < 2 ) mf = 2;

                uf = mf*10/(mf+10);  // ��˵Ʒ��
                sf = mf*30/(mf+30);  // ʷʫƷ��
                rf = mf*500/(mf+500);  // ��ϡƷ��

                rate = random(100);
                /*
                rate2 = random(100);
                rate = (rate + rate2) / 2;
                */
                
                if( mf >= 700 )
                {
                        if( base_type == "weapon" || obj_type == "hands" || obj_type == "finger" )
                                n = 9;       // ��������
                        else if( base_type == "armor" )
                                n = 7;
                        else // �����
                                n = 3;
                        
                        if( mf >= 800 )
                                qlvl = 8;
                        else
                                qlvl = 7;
                                
                        color = HBRED+HIW; // ��
                } else 
                if( mf >= 600 )
                {
                        if( base_type == "weapon" || obj_type == "hands" || obj_type == "finger" )
                                n = 5;       // ��������
                        else if( base_type == "armor" )
                                n = 3;
                        else // �����
                                n = 3;
                        qlvl = 6;
                        color = HBRED+HIW; // ��
                } else
                if( mf >= 500 )
                {
                        if( base_type == "weapon" || obj_type == "hands" || obj_type == "finger" )
                                n = 4;       // ��������
                        else if( base_type == "armor" )
                                n = 3;
                        else // �����
                                n = 3;
                        if( (mf >= 540 && random(300) == 1) || random(1000) == 1 )
                        {
                                //qlvl = 5+random(2);
                                qlvl = 6;
                                if( qlvl == 6 ) color = HBRED+HIW; else color = HIY;
                        }
                        else
                        {
                                qlvl = 5;
                                color = HIY; // ��������
                        }
                } else
                if( mf >= 400 )
                {
                        n = 3;
                        if( !random(5) )
                        {
                                if( random(10000) == 1 )
                                        qlvl = 6;
                                else
                                        qlvl = 4+random(2);
                                if( qlvl == 6 ) color = HBRED+HIW; else if( qlvl == 5 ) color = HIY; else color = HIM;
                        }
                        else
                        {
                                qlvl = 4;
                                color = HIM; // ʷʫ
                        }
                } else
                if( mf >= 300 )
                {
                        n = 2;
                        if( !random(3) )
                        {
                                qlvl = 3+random(3);
                                if( qlvl == 5 ) color = HIY; else if( qlvl == 4 ) color = HIM; else color = HIR;
                        }
                        else
                        {
                                qlvl = 3;
                                color = HIR; // ��ϡ����
                        }
                } else
                if( rate < uf && !random(100) )
                {
                        if( base_type == "weapon" || obj_type == "hands" || obj_type == "finger" )
                                n = 4;       // ��������
                        else if( base_type == "armor" )
                                n = 3;
                        else // �����
                                n = 3;
                        qlvl = 5;
                        color = HIY; // ��˵
                } else
                if( rate < sf && !random(50) )
                {
                        n = 3;
                        qlvl = 4;
                        color = HIM; // ʷʫ
                } else
                if( rate < rf )
                {
                        n = 2;
                        qlvl = 3;
                        color = HIR; // ��ϡ
                }
                else
                if( rate < mf )
                {
                        n = 1;
                        qlvl = 2;
                        color = HIB; // ����
                }
                else
                {
                        n = 0;
                        qlvl = 1;
                        color = HIW; // ��ͨ
                }
                
                // ������Ƕ�ı�ʯ
                if( mf >= 700 )
                {
                        data = apply_props(obj_type, ilvl/10, n, 1);
                        data["flute"] = n; //socket
                        data["used"] = n;
                        insert = data["insert"];
                        map_delete(data, "insert");
                        temp_status["enchase"] = copy(data); // ����װ������ buff/enchase ?
                        temp_status["insert"] = insert;      // ��۱�ʯ����
                }
                else
                {
                        if( n > 1 )
                                n = random(n); // ���������
                        if( n > 0 )
                        {
                                data = apply_props(obj_type, ilvl/10, n, 0);
                                data["flute"] = n; //socket
                                data["used"] = n;
                                insert = data["insert"];
                                map_delete(data, "insert");
                                temp_status["enchase"] = copy(data); // ����װ������ buff/enchase ?
                                temp_status["insert"] = insert;      // ��۱�ʯ����
                        }
                }
                
                if( qlvl > 5 ) // ����
                {
                        if( base_type == "weapon" || obj_type == "hands" || obj_type == "finger" )
                                props = weapon_props[3];
                        else if( base_type == "armor" )
                                props = armor_props[3];
                        else
                                props = ring_props[3];

                        prop = props[random(sizeof(props))];
                        if( !sizeof(applied_prop) || undefinedp(applied_prop[prop]) )
                                applied_prop[prop] = query_prop_value(prop, ilvl/10);
                        else
                                applied_prop[prop] += query_prop_value(prop, ilvl/10);

                        prop = props[random(sizeof(props))];
                        if( !sizeof(applied_prop) || undefinedp(applied_prop[prop]) )
                                applied_prop[prop] = query_prop_value(prop, ilvl/10);
                        else
                                applied_prop[prop] += query_prop_value(prop, ilvl/10);

                        prop = props[random(sizeof(props))];
                        if( !sizeof(applied_prop) || undefinedp(applied_prop[prop]) )
                                applied_prop[prop] = query_prop_value(prop, ilvl/10);
                        else
                                applied_prop[prop] += query_prop_value(prop, ilvl/10);

                        prop = props[random(sizeof(props))];
                        if( !sizeof(applied_prop) || undefinedp(applied_prop[prop]) )
                                applied_prop[prop] = query_prop_value(prop, ilvl/10);
                        else
                                applied_prop[prop] += query_prop_value(prop, ilvl/10);
                } else {
                if( qlvl > 4 ) // ��˵
                {
                        if( base_type == "weapon" || obj_type == "hands" || obj_type == "finger" )
                                props = weapon_props[2];
                        else if( base_type == "armor" )
                                props = armor_props[2];
                        else
                                props = ring_props[2];

                        prop = props[random(sizeof(props))];
                        if( !sizeof(applied_prop) || undefinedp(applied_prop[prop]) )
                                applied_prop[prop] = query_prop_value(prop, ilvl/10);
                        else
                                applied_prop[prop] += query_prop_value(prop, ilvl/10);
                }
                if( qlvl > 3 ) // ʷʫ
                {
                        if( base_type == "weapon" || obj_type == "hands" || obj_type == "finger" )
                                props = weapon_props[1];
                        else if( base_type == "armor" )
                                props = armor_props[1];
                        else
                                props = ring_props[1];

                        prop = props[random(sizeof(props))];
                        if( !sizeof(applied_prop) || undefinedp(applied_prop[prop]) )
                                applied_prop[prop] = query_prop_value(prop, ilvl/10);
                        else
                                applied_prop[prop] += query_prop_value(prop, ilvl/10);
                }
                if( qlvl > 2 ) // ��ϡ
                {
                        if( base_type == "weapon" || obj_type == "hands" || obj_type == "finger" )
                                props = weapon_props[0];
                        else if( base_type == "armor" )
                                props = armor_props[0];
                        else
                                props = ring_props[0];

                        prop = props[random(sizeof(props))];
                        if( !sizeof(applied_prop) || undefinedp(applied_prop[prop]) )
                                applied_prop[prop] = query_prop_value(prop, ilvl/10);
                        else
                                applied_prop[prop] += query_prop_value(prop, ilvl/10);
                }
                }

                if( base_type == "weapon" )
                {
                        temp_status["weapon_prop"] = ([ "damage" : (ilvl+15)*qlvl*10 ]); // ��������-�˺�
                        if( applied_prop )
                                temp_status["weapon_prop"] += applied_prop;
                }
                else if( base_type == "armor" )
                {
                        if( obj_type == "hands"
                        ||  obj_type == "finger" )
                        {
                                temp_status["armor_prop"] = ([ "armor" : 10 ]);
                                temp_status["armor_prop"]+= ([ "unarmed_damage" : (ilvl+15)*qlvl*10 ]);
                                if( applied_prop )
                                        temp_status["armor_prop"] += applied_prop;
                        }
                        else
                        {
                                temp_status["armor_prop"] = ([ "armor" : (ilvl+15)*qlvl*2 ]); // ��������-����
                                if( applied_prop )
                                        temp_status["armor_prop"] += applied_prop;
                        }
                }
                else // �����
                {
                        temp_status["armor_prop"] = ([ "armor" : 10 ]);
                        if( applied_prop )
                                temp_status["armor_prop"] += applied_prop;
                }

                ob = TEMPLATE_D->create_object(filename, obj_type, temp_status);
                set("quality_level", qlvl, ob); // Ʒ��
                set("can_sign", 1, ob); // װ��ǩ��
                set("auto_load", 1, ob); // ���߲���
                if( color )
                        ob->set_color(color); // ������ɫ,x_name���Ѿ�������ɫ�ˣ�
        }
        else // ���䱦ʯ
        {
                // ��ʯ��Ϊ4���ȼ�����Ƭ�����1��ϡ��1+1����֮1+2����ʯӵ�б����ͷ����Լ���Ʒ3�����ԣ�
                // ����δ�����ı�ʯ����
                if( ilvl <= 20 )
                        filename = "/clone/tessera/"+gems1[random(sizeof(gems1))];
                else if( ilvl <= 40 )
                        filename = "/clone/tessera/"+gems2[random(sizeof(gems2))];
                else if( ilvl <= 60 )
                        filename = "/clone/tessera/"+gems3[random(sizeof(gems3))];
                else if( ilvl <= 80 )
                        filename = "/clone/tessera/"+gems4[random(sizeof(gems4))];
                else
                        filename = "/clone/tessera/"+gems5[random(sizeof(gems5))];

                ob = new(filename);
                //file = map_array(get_dir("/inherit/template/gem/"), (: "/inherit/template/gem/" + $1 :));
                //filename = file[random(sizeof(file))];
                //ob = new(filename);
        }

        return ob;
}

public varargs void killer_reward(object killer, object victim, mapping drops)
{
        object ob, *obs;
        string *ks, key, str;
        string ob_file, ob_quality, ob_num, ob_typ;
        int i, n, value, level, team_size, mf;
        int rand, times, score;
        object where;

        if(  !mapp(drops) || !sizeof(drops) )
                return;

        where = environment(victim);
        obs = pointerp(killer->query_team()) ? killer->query_team() : ({ killer });
        team_size = sizeof(filter_array(obs, (: objectp($1) && environment($1) == environment($(killer)) :)));

        times = ACTION_D->query_action("drop_times");
        if( !times ) times = 1;
        if( killer->query_bunch() && BUNCH_D->query_bunch_efficient(killer->query_bunch(), "mf") )
                times *= 2;
        if( killer->query_family() && BUNCH_D->query_bunch_efficient(killer->query_family(), "mf") )
                times *= 2;
        mf=killer->query_all_buff("magic_find");

        if( mf > 300 ) mf = 300;
        score = 0;
        ks = keys(drops);
        for( i=0; i<sizeof(ks); i++ ) {
                key = ks[i];
                score += drops[ks[i]];
        }
        for( i=0; i<sizeof(ks); i++ ) {
                key = ks[i];
                value = drops[ks[i]];
                value += value * mf/100;

                // ���伸�ʹ�ʽ
                if( team_size >= 5 )
                        value = value * 220 / 100;
                else if( team_size == 4 )
                        value = value * 182 / 100;
                else if( team_size == 3 )
                        value = value * 152 / 100;
                else if( team_size == 2 )
                        value = value * 121 / 100;
                for( n=0; n<times; n++ ) {
                        //rand = random(100);
                        rand = random(score);
                        if( rand < value) {
                                str = key[0..1];
                                // �������йؼ����� F I ��ͷ��ʾΪ����ĳ����Ʒ
                                if( str == "FI" ) {
                                        if( sscanf(key, "FI&%s", ob_file) )
                                                ob = new(ob_file);

                                }
                                // �������йؼ����� N U ��ͷ��ʾΪ����ĳ����ŵ���Ʒ
                                else if( str == "NU" ) {
                                        if(  sscanf(key, "NU&%s", ob_num) )
                                                ob = create_object(ob_num);

                                }
                                // �������йؼ����� T Y ��ͷ��ʾΪ����ĳ�����͵���Ʒ
                                else if( str == "TY" ) {
                                        if(  sscanf(key, "TY&%s%d", ob_typ, level) == 2 )
                                                ob = create_dynamic(ob_typ, level, mf);

                                }
                                // �������йؼ����� M O ��ͷ��ʾΪ����ĳ����ŵ���װ����
                                else if( str == "MO" ) {
                                        if( sscanf(key, "MO&%s", ob_num) )
                                                ob = create_module(ob_num);

                                }
                                // �������йؼ����� R A ��ͷ��ʾΪ����ĳ��Ʒ�ʵĵ������Ʒ���������ĳ��װ��
                                else if( str == "RA" ) {
                                        if( sscanf(key, "RA&%s%d", ob_quality, level) == 2 ) {
                                                switch (ob_quality)
                                                {
                                                case "MODULE"   :
                                                        ob = create_module("", level);
                                                        break;
                                                case "NUMBER"   :
                                                        ob = create_object("", level);
                                                        break;
                                                case "RANDOM"   :
                                                        ob = create_dynamic("", level, mf);
                                                        break;
                                                case "RARE"     :
                                                        ob = create_dynamic("", level, 300);
                                                        break;
                                                case "EPIL"     :
                                                        ob = create_dynamic("", level, 400);
                                                        break;
                                                case "LEGEND"   :
                                                        ob = create_dynamic("", level, 500+mf/5);
                                                        break;
                                                case "MYTH"     :
                                                        ob = create_dynamic("", level, 600);
                                                        break;
                                                case "IMMORTAL" :
                                                        ob = create_dynamic("", level, 700);
                                                        break;
                                                case "SUPREME"     :
                                                        ob = create_dynamic("", level, 800);
                                                        break;
                                                default         :
                                                        break;
                                                }
                                        }
                                }
                                if( objectp(ob) ) {
                                        // HIW+treasure_level+NOR" ��"HIC"ϡ"NOR CYN"��"NOR"��Ʒ
/*
                                        if( query("quality_level", ob) == 3 ) // ��ϡ
                                                CHANNEL_D->channel_broadcast("news",
                                                        query("name", killer) + "ɱ��" + victim->name() + NOR YEL"���������ϵ���һ"+query("unit", ob)+HIR" ��"NOR RED"ϡ"HIW"�� "NOR YEL+ob->name()+YEL"��\n"NOR);
                                        else if( query("quality_level", ob) == 4 ) // ʷʫ
                                        if( query("quality_level", ob) == 4 ) // ʷʫ
                                                CHANNEL_D->channel_broadcast("news",
                                                        query("name", killer) + "ɱ��" + victim->name() + NOR YEL"���������ϵ���һ"+query("unit", ob)+HIM" ʷ"NOR MAG"ʫ"HIW"�� "NOR YEL+ob->name()+YEL"��\n"NOR);
*/
                                        if( query("quality_level", ob) == 5 ) // ��˵
                                                CHANNEL_D->channel_broadcast("news",
                                                        query("name", killer) + "ɱ��" + victim->name() + NOR YEL"���������ϵ���һ"+query("unit", ob)+HIY" ��"NOR YEL"˵"HIW"�� "NOR YEL+ob->name()+YEL"��\n"NOR);
                                        else if( query("quality_level", ob) == 6 ) // ����
                                        {
                                                CHANNEL_D->channel_broadcast("news",
                                                        //query("name", killer) + "ɱ��" + victim->name() + NOR YEL"������ʬ���ϼ�����һ"+query("unit", ob)+HIY" ��"NOR YEL"��"HIW"�� "NOR YEL+ob->name()+YEL"��\n"NOR);
                                                        query("name", killer) + "ɱ��" + victim->name() + NOR YEL"���������ϵ���һ"+query("unit", ob)+" "+HBRED+HIW"����"NOR+HIW"�� "NOR YEL+ob->name()+YEL"��\n"NOR);
                                                log_file("myth", sprintf("%s have get a %s(%s) of myth equip at %s.\n",killer->query_idname(),query("name",ob),query("id",ob),TIME_D->replace_ctime(time())));
                                        }                                       
                                        else if( query("quality_level", ob) == 7 ) // ����
                                        {
                                                CHANNEL_D->channel_broadcast("news",
                                                        HIY "�������Ǽ��������Զ������" + (random(2) ? "��Ϣ" : "ζ��") + "��ɢƮ��...\n" + HIC + (random(2) ? "���" : "����") + "~" + (random(2) ? "~" : "") + "~һ����" +  ob->name() + NOR + HIC + "���������\n"NOR);
                                                
                                                if( ob->is_weapon() || ob->is_unarmed_weapon() )
                                                {
                                                        set("combat/MKS", 2100, ob);
                                                        set("owner/"+query("id", killer), 21000000, ob);
                                                        set("magic/imbue_ok", 1, ob);
                                                        set("magic/blood", 21000, ob);
                                                        set("enchase/flute", 9, ob);
                                                        set("enchase/SN", 87, ob);
                                                        IDENTIFY_D->identify_ultimate_ob(ob, 1);
                                                }
                                                else
                                                {
                                                        set("ultimate/37", 1, ob);
                                                        set("ultimate/39", 1, ob);
                                                        set("enchase/flute", 7, ob);
                                                        set("enchase/SN", 69, ob);
                                                        IDENTIFY_D->identify_ultimate_ob(ob, 1);
                                                }

                                                log_file("myth", sprintf("%s have get a %s(%s) of immortal equip at %s.\n",killer->query_idname(),query("name",ob),query("id",ob),TIME_D->replace_ctime(time())));
                                        }

                                        else if( query("quality_level", ob) == 8 ) // ����
                                        {
                                                CHANNEL_D->channel_broadcast("news",
                                                        HIK "�ڰ���ɫ��ҫ��أ�̫�ź��" + (random(2) ? "��Ϣ" : "ζ��") + "������Ϣ...\n" + HIC + (random(2) ? "���" : "����") + "~" + (random(2) ? "~" : "") + "~һ����" +  ob->name() + NOR + HIC + "���������\n"NOR);
                                               
                                                if( ob->is_weapon() || ob->is_unarmed_weapon() )
                                                {
                                                        set("combat/MKS", 2100, ob);
                                                        set("owner/"+query("id", killer), 21000000, ob);
                                                        set("magic/imbue_ok", 1, ob);
                                                        set("magic/blood", 21000, ob);
                                                        set("enchase/flute", 9, ob);
                                                        set("enchase/SN", 105, ob);
                                                        IDENTIFY_D->identify_ultimate_ob(ob, 1);
                                                }
                                                else
                                                {
                                                        set("ultimate/37", 1, ob);
                                                        set("ultimate/39", 1, ob);
                                                        set("enchase/flute", 7, ob);
                                                        set("enchase/SN", 87, ob);
                                                        IDENTIFY_D->identify_ultimate_ob(ob, 1);
                                                }

                                                log_file("myth", sprintf("%s have get a %s(%s) of immortal equip at %s.\n",killer->query_idname(),query("name",ob),query("id",ob),TIME_D->replace_ctime(time())));
                                        }
                                                                                
                                        message_vision(HIC "��~~һ������$N" HIC "���ϵ���" + ob->name() + NOR + HIC "�����ڵ��ϡ�\n" NOR, victim);
                                        if( query("quality_level", ob) > 2 ) {
                                                set("who_get/id", query("id", killer), ob);
                                                set("who_get/time", time() + 10, ob); // 10���ڱ��˶����ܼ�ȡ
                                        }
                                        ob->move(where);
                                }
                        }
                }
        }
        /*
        mf=killer->query_all_buff("gold_find");
        if( random(100) < mf )
        {
                ob = new("/clone/money/gold");
                ob->set_amount(random(20)+20);
                ob->move(where);
                message_vision(HIC "��~~һ������$N" HIC "���ϵ���" + ob->name() + NOR + HIC "�����ڵ��ϡ�\n" NOR, victim);
        }
        */

        // ��������Ʒ��ͳһ����giftd�ӿ�
        //GIFT_D->boss_drops(this_object());

        return;
}

// ��������Ʒ
void festival_drops(object me);
