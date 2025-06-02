// This program is a part of NT MudLIB

#include <ansi.h>

// "str","��ɫ����ֵ��ߣ���\t",500,

mapping max_ability = ([
        "str"   : 500,
        "int"   : 500,
        "con"   : 500,
        "dex"   : 500,
        "kar"   : 70,
        "max_qi"    : 10,
        "max_jing"  : 10,
        "max_neili" : 10,
        "max_jingli": 10,
        "qi_recover": 20,
        "jing_recover" : 20,
        "neili_recover": 20,
        "attack": 10,
        "dodge" : 10,
        "parry" : 10,
        "double_damage": 10,
        "avoid_poison" : 10,
        "avoid_busy": 10,
        "avoid_weak": 10,
        "reduce_damage": 10,
]);

// ��������
string *bas_ability = ({
        "str",
        "int",
        "con",
        "dex",
        "kar",
        "max_qi",
        "max_jing",
        "max_neili",
        "max_jingli",
        "qi_recover",
        "jing_recover",
        "neili_recover",
        "attack",
        "dodge",
        "parry",
        "double_damage",
        "avoid_poison",
        "avoid_busy",
        "avoid_weak",
        "reduce_damage",
});

string *bas_ability_info = ({
        "��ɫ����ֵ��ߣ���\t","��ɫ����ֵ��ߣ���\t","��ɫ����ֵ��ߣ���\t",
        "��ɫ��ֵ��ߣ���\t","��ɫ����ֵ��ߣ���\t","�����Ѫֵ��ߣ���\t",
        "�����ֵ��ߣ���\t","�������ֵ��ߣ���\t","�����ֵ��ߣ���\t",
        "�ָ���Ѫ��ߣ�����\t","�ָ�������ߣ�����\t","�ָ�������ߣ�����\t",
        "ֱ�����л���������\t","ֱ�����ܻ���������\t","ֱ���мܻ���������\t",
        "������������������\t","���߶��ػ���������\t","����æ�һ���������\t",
        "������������������\t","�����˺�����������\t",
});

mapping bas_ability_pot = ([
        "attack":       2,
        "dodge":        2,
        "parry":        2,
        "double_damage":3,
        "avoid_poison": 3,
        "avoid_busy":   3,
        "avoid_weak":   3,
        "reduce_damage":3,
]);

mapping fam_ability_pot = ([
        //5
]);

mapping fam_ability_data = ([
        //5
]);

mapping fam_ability = ([
        "������": ({
                "dodgeup-shaolin-shenfa", "parryup-jingang-buhuaiti", "cd-jgbht-protect", "cd-yjj-buddha", "ap_power-ryb-shang",
                "da_power-ryb-shang", "ap_power-lhj-lunhui", "da_power-lhj-lunhui", "cd-lhj-lunhui",
        }),

        "�䵱��": ({
                "dodgeup-tiyunzong", "parryup-taiji-quan", "parryup-taiji-jian", "ap_power-tjq-tu", "da_power-tjq-tu", "cd-tjq-tu",
                "ap_power-tjq-zhen", "da_power-tjq-zhen", "ap_power-tjj-jian", "da_power-tjj-jian", "cd-tjj-jian",
        }),

        "������": ({
                "dodgeup-zhutian-bu", "parryup-piaoxue-zhang", "ap_power-pxz-zhao", "parryup-huifeng-jian", "ap_power-hfj-jue", "da_power-hfj-jue", "cd-ljz-niepan"
        }),

        "��ɽ��": ({
                "powerup-zxsg-ziqi", "dodgeup-feiyan-huixiang", "parryup-lonely-sword", "ap_power-dgjj-hun", "da_power-dgjj-hun", "fatal_blow-dgjj-hun",
                "cd-dgjj-hun", "ap_power-dgjj-xiao", "da_power-dgjj-xiao", "fatal_blow-dgjj-xiao",
        }),

        "�һ���": ({
                "dodgeup-luoying-shenfa", "parryup-yuxiao-jianfa", "parryup-tanzhi-shentong", "ap_power-yxjf-bihai", "da_power-yxjf-bihai",
                "ap_power-tzst-dian", "da_power-tzst-dian", "cd-tzst-dian", "ap_power-tzst-zhuan", "da_power-tzst-zhuan", "cd-tzst-lingxi",
        }),

        "ŷ������":({
                "dodgeup-chanchu-bufa", "parryup-hamagong", "powerup-hmg-reserve", "ap_power-hmg-zhen", "da_power-hmg-zhen",
                "cd-hmg-nizhuan",
        }),

        "���ϻ���":({
                "full-krcg-kurong", "dodgeup-tiannan-bu", "parryup-six-finger", "ap_power-lmsj-gz", "da_power-lmsj-gz",
                "ap_power-lmsj-tian", "da_power-lmsj-tian", "cd-lmsj-tian", "ap_power-yyz-die", "da_power-yyz-die",
                "ap_power-yyz-jian", "da_power-yyz-jian",
        }),

        "ؤ��"  : ({
                "dodgeup-feiyan-zoubi", "parryup-dragon-strike", "ap_power-dgb-tian", "ap_power-xlsbz-hui", "da_power-xlsbz-hui",
                "double_damage-xlsbz-hui","ap_power-xlsbz-long", "da_power-xlsbz-long", "double_damage-xlsbz-long", "cd-xlsbz-long",
        }),

        "ȫ���": ({
                "dodgeup-jinyan-gong", "parryup-kongming-quan", "ap_power-hubo", "ap_power-xtg-xian", "da_power-xtg-xian", "cd-xtg-xian",
                "ap_power-xtg-jian", "da_power-xtg-jian", "ap_power-xtg-shen", "da_power-xtg-shen",
        }),

        "��Ĺ��": ({
                "powerup-nhkt-haixiao", "dodgeup-yunv-shenfa", "parryup-xuantie-jian", "parryup-sad-strike", "parryup-yunv-jian", "ap_power-hubo",
                "ap_power-arxhz-tuo", "da_power-arxhz-tuo", "cd-arxhz-tuo", "cd-ynxf-wuzhi",
        }),

        "����"  : ({
                "dodgeup-qingfu-shenfa", "parryup-qiankun-danuoyi", "ap_power-jysg-ri", "da_power-jysg-ri", "cd-jysg-ri",
                "ap_power-qkdny-yi", "da_power-qkdny-yi", "cd-qkdny-nuozhuan", "power-qkdny-nuozhuan", "ap_power-shl-can",
        }),

        "ħ��"  : ({
                "powerup-cykzj-huaxue", "dodgeup-jiutian-xiaoyaobu", "parryup-moshen-zhenshen", "ap_power-tymyd-mingyue", "da_power-tymyd-mingyue",
                "ap_power-yywd-ting", "da_power-yywd-ting", "fatal_blow-yywd-ting", "ap_power-yywd-dao", "da_power-yywd-dao",
                "fatal_blow-yywd-dao", "cd-yywd-ting", "cd-yywd-dao",
        }),

        "�������":({
                "powerup-rygh-richu", "dodgeup-pixie-jian", "parryup-pixie-jian", "add-khxf-sneaky", "ap_power-pxj-you",
                "da_power-pxj-you", "powerup-pxj-jian",
        }),

        "������": ({
                "powerup_hgdf-suck", "dodgeup-feixing-shu", "parryup-chousui-zhang", "ap_power-csz-shi", "da_power-csz-shi", "ap_power-csz-tao",
                "da_power-csz-tao", "cd-freezing-hanmo",
        }),

        "��ң��": ({
                "powerup-bmsg-suck", "dodgeup-lingbo-weibu", "parryup-liuyang-zhang", "parryup-zhemei-shou", "cd-lbwb-shen", "ap_power-lyz-hui",
                "da_power-lyz-hui", "ap_power-zms-hua", "da_power-zms-hua",
        }),

        "���չ�": ({
                "dodgeup-yueying-wubu", "parryup-liuyang-zhang", "ap_power-lyz-zhen", "da_power-lyz-zhen", "ap_power-lyz-zun", "da_power-lyz-zun",
                "cd-bhg-protect",
        }),

        "������": ({
                "dodgeup-yixing-bufa", "parryup-shedao-qigong", "ap_power-bssl-zhou", "ap_power-sdqg-xian", "da_power-sdqg-xian",
                "ap_power-sdqg-hou", "da_power-sdqg-hou",
        }),

        "Ѫ����": ({
                "powerup-xhmg-jixue", "dodgeup-shenkong-xing", "parryup-xuedao-daofa", "ap_power-xddf-xue", "da_power-xddf-xue",
                "ap_power-szj-ying", "da_power-szj-ying", "ap_power-xddf-huan", "da_power-xddf-huan", "cd-xddf-huan",
        }),

        "ѩɽ��": ({
                "dodgeup-shenkong-xing", "parryup-longxiang-gong", "ap_power-lxbrg-zhen", "da_power-lxbrz-zhen", "ap_power-ryl-lian",
                "ap_power-lxbrg-longxiang", "da_power-lxbrg-longxiang", "cd-lxbrg-longxiang",
        }),

        "����": ({
                "powerup-xhmg-jixue", "dodgeup-shenkong-xing", "parryup-xuedao-daofa", "ap_power-xddf-xue", "da_power-xddf-xue",
                "ap_power-szj-ying", "da_power-szj-ying", "ap_power-xddf-huan", "da_power-xddf-huan", "cd-xddf-huan",
                "dodgeup-shenkong-xing", "parryup-longxiang-gong", "ap_power-lxbrg-zhen", "da_power-lxbrz-zhen", "ap_power-ryl-lian",
                "ap_power-lxbrg-longxiang", "da_power-lxbrg-longxiang", "cd-lxbrg-longxiang",
        }),

        "�嶾��": ({
                "dodgeup-wudu-yanluobu", "ap_power-wdsg-arrow", "parryup-qianzhu-wandushou", "ap_power-qzwds-chuan", "da_power-qzwds-chuan",
                "ap_power-qzwds-qzwd", "da_power-qzwds-qzwd", "cd-qzwds-qzwd", 
                "cd-bdjcg-summon", "max-bdjcg-summon", "chance-bdjcg-protect", "n-bdjcg-grow1", "n--bdjcg-grow2", 
                "cd-bdjcg-wpin", "ap_power-bdjcg-wpin", "da_power-bdjcg-wpin", "da_power-bdjcg-wpin2", "da_power-bdjcg-wpin3",
                "chance-bdjcg-cpin", "hp-bdjcg", "reduce_damage-bdjcg", "avoid_die-bdjcg",
        }),

        "�������":({
                "dodgeup-sixiang-bufa", "parryup-daojian-guizhen", "defdown-lengyue", "ap_power-hjdf-pi", "da_power-hjdf-pi",
                "ap_power-djgz-tian", "da_power-djgz-tian", "ap_power-djgz-jiu", "da_power-djgz-jiu", "cd-djgz-jiu",
                "power-msqd-despel",
        }),

        "Ľ������":({
                "dodgeup-beidou-xianzong", "parryup-douzhuan-xingyi", "ap_power-chz-canhe", "da_power-chz-canhe",
                "ap_power-dzxy-yi", "cd-dzxy-yi",
        }),

        "��������":({
                "dodgeup-qiulin-sheye", "parryup-boyun-suowu", "ap_power-tmaq-san", "da_power-tmaq-san",
                "ap_power-tmaq-hua", "da_power-tmaq-hua", "ap_power-tmaq-shijie", "cd-tmaq-shijie",
        }),
]);

mapping fam_ability_info = ([
// ���У��˺����������мܣ���CD, ����Ч��ʱ��������������ʣ�����һ��
// ����Ч����æ�ң�����������
        "������": ({
                "���������ܻ��ᣫ����\t",
                "��ղ������мܻ��ᣫ����",
                "��ղ���CDʱ����٣���\t",
                "�������CDʱ����٣���\t",
                "���־����л��ᣫ����\t",
                "���־��˺���������\t",
                "�����ֻ����л��ᣫ����\t",
                "�����ֻ��˺���������\t",
                "�����ֻ�CDʱ����٣���\t",
        }),

        "�䵱��": ({
                "���������ܻ��ᣫ����\t",
                "̫��ȭ�мܻ��ᣫ����\t",
                "̫�����мܻ��ᣫ����\t",
                "̫��ͼ���л��ᣫ����\t",
                "̫��ͼ�˺���������\t",
                "̫��ͼCDʱ����٣���\t",
                "�����а���л��ᣫ����\t",
                "�����а�˺���������\t",
                "̫�O�������л��ᣫ����\t",
                "̫�O�����˺���������\t",
                "̫�O����CDʱ����٣���\t",
        }),

        "������"  : ({
                "���컯�����ܻ��ᣫ����",
                "Ʈѩ�������мܻ��ᣫ����",
                "����������л��ᣫ����\t",
                "�ط�������мܻ��ᣫ����",
                "�������л��ᣫ����\t",
                "�����˺���������\t",
                "�������CDʱ����٣���\t",
        }),

        "��ɽ��": ({
                "���������ӳ��˺�Ч��������",
                "����������ܻ��ᣫ����\t",
                "���¾Ž������ط����ᣫ����",
                "�������л��ᣫ����\t",
                "�����˺���������\t",
                "����׷������һ���������ʣ�����",
                "����CDʱ����٣���\t",
                "�׺�Ц���л��ᣫ����\t",
                "�׺�Ц�˺���������\t",
                "�׺�Ц׷������һ���������ʣ�����",
        }),

        "�һ���": ({
                "��Ӣ�����ܻ��ᣫ����\t",
                "���｣���мܻ��ᣫ����\t",
                "��ָ��ͨ�мܻ��ᣫ����\t",
                "�̺��������������л��ᣫ����",
                "�̺������������˺���������",
                "���յ�Ѩ���л��ᣫ����\t",
                "���յ�Ѩ�˺���������\t",
                "���յ�ѨCDʱ����٣���\t",
                "תǬ�����л��ᣫ����\t",
                "תǬ���˺���������\t",
                "��ϬһָCDʱ����٣���\t",
        }),

        "ŷ������": ({
                "��ܲ������ܻ��ᣫ����\t",
                "��󡹦�мܻ��ᣫ����\t",
                "������ת�ӳֹ���Ч��������",
                "���������л��ᣫ����\t",
                "���������˺���������\t",
                "��ת����CDʱ����٣���\t",
        }),

        "���ϻ���": ({
                "�����ķ��Ļ�ѪЧ��������",
                "���ϲ������ܻ��ᣫ����\t",
                "�������мܻ��ᣫ����\t",
                "�����������л��ᣫ����\t",
                "���������˺���������\t",
                "���������л��ᣫ����\t",
                "�������˺���������\t",
                "������CDʱ����٣���\t",
                "�����������л��ᣫ����\t",
                "���������˺���������\t",
                "���칦Ǭ���������л��ᣫ����",
                "���칦Ǭ�������˺���������",
        }),

        "ؤ��"  : ({
                "�����߱����ܻ��ᣫ����\t",
                "����ʮ�����мܻ��ᣫ����",
                "�����޹����л��ᣫ����\t",
                "�����л����л��ᣫ����\t",
                "�����л��˺���������\t",
                "�����л�׷�ӱ����������ʣ�����",
                "���[�������л��ᣫ����\t",
                "���[�����˺���������\t",
                "���[����׷�ӱ����������ʣ�����",
                "���[����CDʱ����٣���\t",
        }),

        "ȫ���": ({
                "���㹦���ܻ��ᣫ����\t",
                "����ȭ�мܻ��ᣫ����\t",
                "���һ��������У�����\t",
                "����������л��ᣫ����\t",
                "��������˺���������\t",
                "�������CDʱ����٣���\t",
                "���칦Ǭ���������л��ᣫ����",
                "���칦Ǭ�������˺���������",
                "������ͨ�����л��ᣫ����",
                "������ͨ���˺���������\t",
        }),

        "��Ĺ��": ({
                "����һХЧ��������\t",
                "��Ů�����ܻ��ᣫ����\t",
                "���������мܻ��ᣫ����\t",
                "��Ȼ�������мܻ��ᣫ����",
                "��Ů�����мܻ��ᣫ����\t",
                "���һ��������У�����\t",
                "�����ˮ���л��ᣫ����\t",
                "�����ˮ�˺���������\t",
                "�����ˮCDʱ����٣���\t",
                "��������CDʱ����٣���\t",
        }),

        "����"  : ({
                "���������ܻ��ᣫ����\t",
                "Ǭ����Ų���мܻ��ᣫ����",
                "ħ�����޼����л��ᣫ����",
                "ħ�����޼��˺���������\t",
                "ħ�����޼�CDʱ����٣���",
                "��Ų�����л��ᣫ����\t",
                "��Ų���˺���������\t",
                "ŲתǬ��CDʱ����٣���\t",
                "ŲתǬ������Ч��������\t",
                "��Ѫ�����л��ᣫ����\t",
        }),

        "ħ��"  : ({
                "�񵶻�Ѫ�ӳ��˺�Ч��������",
                "������ң�����ܻ��ᣫ����",
                "ħ�������мܻ��ᣫ����\t",
                "�����������л��ᣫ����\t",
                "���������˺���������\t",
                "С¥һҹ���������л��ᣫ����",
                "С¥һҹ�������˺���������",
                "С¥һҹ������׷������һ���������ʣ�����",
                "������-���ϵ����л��ᣫ����",
                "������-���ϵ��˺���������",
                "������-���ϵ�׷������һ���������ʣ�����",
                "С¥һҹ������Ⱥ��CDʱ����٣���",
                "������-���ϵ�CDʱ����٣���",
        }),

        "�������":({
                "�ճ������ӳ��˺�Ч��������",
                "��а�����ܻ��ᣫ����\t",
                "��а���мܻ��ᣫ����\t",
                "����ʱ�䣫����\t",
                "��ڤһ�����л��ᣫ����\t",
                "��ڤһ���˺���������\t",
                "��а��Ӱ���м��˺�������",
        }),

        "������": ({
                "��������ȡ����Ч��������",
                "���������ܻ��ᣫ����\t",
                "�������мܻ��ᣫ����\t",
                "��ʬ�����л��ᣫ����\t",
                "��ʬ���˺���������\t",
                "�����������л��ᣫ����\t",
                "���������˺���������\t",
                "��ħ����CDʱ����٣���\t",
        }),

        "��ң��": ({
                "��ڤ����ȡ����Ч��������",
                "�貨΢�����ܻ��ᣫ����\t",
                "��ɽ�������мܻ��ᣫ����",
                "��÷���мܻ��ᣫ����\t",
                "������CDʱ����٣���\t",
                "�ҷ��������л��ᣫ����\t",
                "�ҷ������˺���������\t",
                "���������л��ᣫ����\t",
                "�������˺���������\t",
        }),

        "���չ�": ({
                "��Ӱ�貽���ܻ��ᣫ����\t",
                "��ɽ�������мܻ��ᣫ����",
                "һ���������л��ᣫ����\t",
                "һ�������˺���������\t",
                "�˻Ķ��������л��ᣫ����",
                "�˻Ķ������˺���������\t",
                "�˻Ķ�����CDʱ����٣���",
                "Ψ�Ҷ���CDʱ����٣���\t",
        }),

        "������": ({
                "���β������ܻ��ᣫ����\t",
                "�ߵ��湦�мܻ��ᣫ����\t",
                "�䷨���л��ᣫ����\t",
                "�����������л��ᣫ����\t",
                "���������˺���������\t",
                "���־����л��ᣫ����\t",
                "���־��˺���������\t",
        }),

        "Ѫ����": ({
                "��Ѫ�󷨼ӳ��˺�Ч��������",
                "��������ܻ��ᣫ����\t",
                "Ѫ�������мܻ��ᣫ����\t",
                "��Ѫ�����л��ᣫ����\t",
                "��Ѫ���˺���������\t",
                "��Ӱ��ȭ���л��ᣫ����\t",
                "��Ӱ��ȭ�˺���������\t",
                "�ұػ�֮���л��ᣫ����\t",
                "�ұػ�֮�˺���������\t",
                "�ұػ�֮CDʱ����٣���\t",
        }),

        "ѩɽ��": ({
                "��������ܻ��ᣫ����\t",
                "����������мܻ��ᣫ����",
                "�桤���������л��ᣫ����",
                "�桤�������˺���������\t",
                "������ת���к��˺�������",
                "ʮ��ʮ�����л��ᣫ����\t",
                "ʮ��ʮ���˺���������\t",
                "ʮ��ʮ��CDʱ����٣���\t",
        }),

        "����": ({
                "��Ѫ�󷨼ӳ��˺�Ч��������",
                "��������ܻ��ᣫ����\t",
                "Ѫ�������мܻ��ᣫ����\t",
                "��Ѫ�����л��ᣫ����\t",
                "��Ѫ���˺���������\t",
                "��Ӱ��ȭ���л��ᣫ����\t",
                "��Ӱ��ȭ�˺���������\t",
                "�ұػ�֮���л��ᣫ����\t",
                "�ұػ�֮�˺���������\t",
                "�ұػ�֮CDʱ����٣���\t",
                "��������ܻ��ᣫ����\t",
                "����������мܻ��ᣫ����",
                "�桤���������л��ᣫ����",
                "�桤�������˺���������\t",
                "������ת���к��˺�������",
                "ʮ��ʮ�����л��ᣫ����\t",
                "ʮ��ʮ���˺���������\t",
                "ʮ��ʮ��CDʱ����٣���\t",
        }),

        "�嶾��": ({
                "�嶾���ܲ����ܻ��ᣫ����",
                "��Ѫ�����л��ᣫ����\t",
                "ǧ�������мܻ��ᣫ����",
                "�򶾴������л��ᣫ����\t",
                "�򶾴����˺���������\t",
                "ǧ�������л��ᣫ����\t",
                "ǧ�����˺���������\t",
                "ǧ����CDʱ����٣���\t",
                "��Ϲ��ٻ�CDʱ�����\t",
                "��Ϲ�����ٻ�������.��\t",
                "��Ϲƻ������ᣫ����\t",
                "��ϹƳɳ��ٶȣ�������\t",
                "��ϹƳɳ��ٶ��٣�������\t",
                "��Ϲư���CDʱ����٣���\t",
                "��Ϲư������л��ᣫ����\t",
                "��Ϲư����˺���������\t",
                "��Ϲ����NPC�˺�����������\t",
                "��Ϲ����NPC�˺����٣�������\t",
                "��ϹƲ��봥���������\t",
                "��ϹƵģȣ�����������\t",
                "��ϹƼ����˺�����������\t",
                "��Ϲ���������ļ������\t",
        }),

        "�������":({
                "���󲽷����ܻ��ᣫ����\t",
                "���������мܻ��ᣫ����\t",
                "���º���Ӱ��������ܣ�����",
                "�����������л��ᣫ����\t",
                "����ٵ��˺���������\t",
                "�������������л��ᣫ����",
                "�����������˺���������\t",
                "�������������л��ᣫ����",
                "�����������˺���������\t",
                "����������CDʱ����٣���",
                "��������Ч��������\t",
        }),

        "Ľ������":({
                "�����������ܻ��ᣫ����\t",
                "��ת�����мܻ��ᣫ����\t",
                "�κϽ������л��ᣫ����\t",
                "�κϽ����˺���������\t",
                "��ת�������л��ᣫ����\t",
                "��ת����CDʱ����٣���\t",
        }),

        "��������":({
                "����ʰҶ���ܻ��ᣫ����\t",
                "���������мܻ��ᣫ����\t",
                "ɢ����Ů���л��ᣫ����\t",
                "ɢ����Ů�˺���������\t",
                "�ƻ����л��ᣫ����\t",
                "�ƻ��˺���������\t\t",
                "һ��һ�������л��ᣫ����",
                "һ��һ����CDʱ����٣���",
        }),
]);

string *talent_ability = ({
        "research_effect",
        "derive_effect",
        "practice_effect",
        "add_exp",
        "magic_find",
        "add_con",
        "qi_recover",
        "jing_recover",
        "neili_recover",
        "avoid_boss_perform",
        "add_boss_defense",
        "add_boss_damage",
        "attack",
        "parry",
        "dodge",
        "double_damage",
        "avoid_dodge",
        "reduce_cd",
        "avoid_busy",
        "avoid_weak",
        "add_damage",
        "reduce_damage",
        "add_forget",
        "avoid_pot_penalty",
        "powerup_blade",
        "powerup_sword",
        "powerup_unarmed",
        "powerup_throwing",
        "powerup_poison",
        "avoid_die",
        "full_self",
        "fatal_blow",
});

mapping max_talent_ability = ([
        "research_effect" : 1,
        "derive_effect"   : 1,
        "practice_effect" : 1,
        "add_exp"         : 2,
        "magic_find"      : 2,
        "add_con"         : 2,
        "qi_recover"      : 3,
        "jing_recover"    : 2,
        "neili_recover"   : 2,
        "avoid_boss_perform" : 3,
        "add_boss_defense"   : 4,
        "add_boss_damage"    : 3,
        "attack"          : 3,
        "parry"           : 3,
        "dodge"           : 3,
        "double_damage"   : 5,
        "avoid_dodge"     : 5,
        "reduce_cd"       : 2,
        "avoid_busy"      : 3,
        "avoid_weak"      : 3,
        "add_damage"      : 5,
        "reduce_damage"   : 3,
        "add_forget"      : 3,
        "avoid_pot_penalty"  : 5,
        "powerup_blade"   : 5,
        "powerup_sword"   : 5,
        "powerup_unarmed" : 5,
        "powerup_throwing" : 5,
        "powerup_poison" : 5,
        "avoid_die"       : 5,
        "full_self"       : 5,
        "fatal_blow"      : 5,
]);

mapping talent_ability_data = ([
        "research_effect" : 20,
        "derive_effect"   : 20,
        "practice_effect" : 20,
        "add_exp"         : 5,
        "magic_find"      : 5,
        "add_con"         : 5,
        "qi_recover"      : 10,
        "jing_recover"    : 10,
        "neili_recover"   : 10,
        "avoid_boss_perform" : 10,
        "add_boss_defense"   : 5,
        "add_boss_damage"    : 5,
        "attack"          : 3,
        "parry"           : 3,
        "dodge"           : 3,
        "double_damage"   : 4,
        "avoid_dodge"     : 4,
        "reduce_cd"       : 5,
        "avoid_busy"      : 3,
        "avoid_weak"      : 3,
        "add_damage"      : 4,
        "reduce_damage"   : 5,
        "add_forget"      : 3,
        "avoid_pot_penalty"  : 5,
        "powerup_blade"   : 4,
        "powerup_sword"   : 4,
        "powerup_unarmed" : 4,
        "powerup_throwing" : 4,
        "powerup_poison" : 4,
        "avoid_die"       : 2,
        "full_self"       : 2,
        "fatal_blow"      : 2,
]);

string *talent_ability_info = ({
        "���У��о�Ч�����20%",
        "��˼����ȡЧ�����20%",
        "��������ϰЧ�����20%",
        "���̣������л�ȡ�����������5%��10%��",
        "���ˣ�װ�����伸������5%��10%��",
        "���ӣ����ɹ��׶�������5%��10%��",
        "ս��ս��ʱ�Զ��ָ���Ѫ�ٶ����10%��20%��30%",
        "ս�飺ս��ʱ�Զ��ָ������ٶ�10%��20%",
        "ս��ս�����Զ��ָ������ٶ�10%��20%",
        "������ʹ�����10%��20%��30%�ļ��ʷ�ֹ����ı�ɱ��",
        "��գ����Ӷ�boss����ľ��Է���5%��10%�㡢15%��20%",
        "��ħ�����Ӷ�boss����ľ����˺�5%��10%�㡢15%��",
        "ӥ�ۣ���������3%��6%��9%",
        "�񵲣��м�����3%��6%��9%",
        "���٣���������3%��6%��9%",
        "������˫���˺���������4%��8%��12%��16%��20%",
        "ǿϮ��4%��8%��12%��16%��20%�Ļ������Ṧ�������������Ч",
        "���棺�����书���е���ȴʱ�併��5�롢10��",
        "��ң��ս������3%��6%��9%�Ļ�������æ��",
        "�������ӵֿ���������3%��6%��9%",
        "����������4%��8%��12%��16%��20%���˺�Ч��",
        "�ػ�������5%��10%��15%���˺�Ч��",
        "�������ö�����3%��6%��9%�ļ�����������",
        "��ͣ�����ʱ��5%��10%��15%��20%��25%�Ļ��ʲ���Ǳ��",
        "���ʣ�ʹ�õ����书����4%��8%��12%��16%��20%�����м��˺�",
        "��ʥ��ʹ�ý����书����4%��8%��12%��16%��20%�����м��˺�",
        "ȭ����ʹ��ȭ���书����4%��8%��12%��16%��20%�����м��˺�",
        "���ɣ�ʹ�ð�����������4%��8%��12%��16%��20%�����м��˺�",
        "����������4%��8%��12%��16%��20%�ļ����Ƴ�����ȶԶ�������",
        "���������������ļ������2%��4%��6%��8%��10%",
        "��ս����Ѫ�����Զ��ָ��������2%��4%��6%��8%��10%",
        "��ɱ��ս�����������һ���ļ������2%��4%��6%��8%��10%",
});

int do_ability_cost(object ob, string arg, int flag);
int check_ability(object me,string arg, int flag);
int check_ability_count(object me,string arg, int flag);
int improve_ability(object me,string arg, int flag);
int valid_ability_improve(object me, string arg, int flag);
string get_ability_idf(object me,string arg, int flag);
string get_ability_info(object ob, string arg, int flag);

int valid_ability_improve(object me, string arg, int flag)
{
        int level;
        int a_lvl;
        int u_lvl;

        a_lvl = check_ability_count(me, arg, flag);
        if( flag == 2 )
                level = max_talent_ability[arg];
        else
                level = max_ability[arg];
        if( !level ) level = 5;
        if( a_lvl >= level )
                return 0;

        u_lvl = query("level", me);
        if( flag == 0 && u_lvl < 10 ) {
                return 0;
        }
        if( flag == 1 && u_lvl < 20 ) {
                return 0;
        }
        if( flag == 2 ) {
                return 1;
        }

        return 1;
}

varargs int check_ability(object me,string arg, int flag)
{
        int result;

        if( flag == 2 )
                // �츳����
                result = query("talent/" + arg, me);
        else
                // Ability ����
                result=query("ability2/"+query("family/family_name", me)+"/"+arg, me)+query("ability1/"+arg, me);

        return result;
}

varargs int check_ability_count(object me,string arg, int flag)
{
        int result;

        if( flag == 2 )
                // �츳����
                result = query("talent_count/" + arg, me);
        else
                // Ability ����
                result=query("ability_count/"+me->query_family()+"/"+arg, me)+query("ability_count/"+arg, me);

        return result;
}

int check_ability_cost(object me, string arg, int flag)
{
        int cost;

        if( flag == 1 ) {
                if( !undefinedp(fam_ability_pot[arg]) )
                        cost = fam_ability_pot[arg];
                else
                        cost = 5;
        } else if( flag == 2 ) {
                cost = 1;
        } else {
                if( member_array(arg, bas_ability) == -1 ) {
                        return 0;
                }
                cost = bas_ability_pot[arg];
                if( !cost ) {
                        cost = 1;
                }
        }
        return cost;
}

// ÿ�κķ�һ�������㼰ʮ���Ǳ��
int do_ability_cost(object me, string arg, int flag)
{
        int cost, pot;

        cost = check_ability_cost(me, arg, flag);
        pot  = cost * 100000;
        if( query("potential", me) - query("learned_potential", me) < pot )
                return 0;

        if( flag == 1 || flag == 0 ) {
                if( cost > query("ability", me)-query("learned_ability", me) ) {
                        return 0;
                }
                addn("learned_ability", cost, me);
                addn("learned_potential", pot, me);
        }

        if( flag == 2 ) {
                if( cost > query("energy", me)-query("learned_energy", me) ) {
                        return 0;
                }
                addn("learned_energy", cost, me);
                addn("learned_potential", pot, me);
        }
        return 1;
}

int improve_ability(object me,string arg, int flag)
{
        int lv, n;
        string myclass;

        myclass = query("family/family_name", me);
        if( !flag ) {
                addn("ability1/"+arg, 1, me);
                addn("ability_count/"+arg, 1, me);
        } else if( flag == 1 ) {
                if( !undefinedp(fam_ability_data[arg]) )
                        n = fam_ability_data[arg];
                else
                        n = 5;
                addn("ability2/"+myclass+"/"+arg, n, me);
                addn("ability_count/"+myclass+"/"+arg, 1, me);
        } else if( flag == 2 ) {
                if( !undefinedp(talent_ability_data[arg]) )
                        n = talent_ability_data[arg];
                else
                        n = 1;
                addn("talent/"+arg, n, me);
                addn("talent_count/"+arg, 1, me);
        }
        return 1;
}

string get_ability_info(object ob, string arg, int flag)
{
        int lv, cost, n;
        string desc, msg, myclass;

        //lv = check_ability(ob, arg, flag);
        cost = check_ability_cost(ob, arg, flag);
        desc = get_ability_idf(ob,arg,flag);
        if( flag == 1 ) {
                // ability's ���ɼ���
                myclass=query("family/family_name", ob);
                if( arrayp(fam_ability[myclass]) ) {
                        n = member_array(arg,fam_ability[myclass]);
                        if( n != -1 ) {
                                msg = fam_ability_info[myclass][n];
                                msg = sprintf(msg+"\t%-12s"HIC"%5d\n"NOR,desc, cost);
                                return msg;
                        }
                }
                return "";
        }

        if( flag == 2 ) {
                n = member_array(arg,talent_ability);
                if( n != -1 ) {
                        msg = talent_ability_info[n];
                        msg = sprintf("%-60s%-12s"HIC"%5d\n"NOR, msg, desc, cost);
                        return msg;
                }
                return "";
        }

        n = member_array(arg, bas_ability);
        if( n != -1 ) {
                msg = bas_ability_info[n];
                msg = sprintf(msg+"\t%-12s"HIC"%5d\n"NOR, desc, cost);
                return msg;
        }
        return "";
}


string get_ability_idf(object me,string arg, int flag)
{
        int level;
        int lev = check_ability_count(me,arg,flag);
        // 1,2,3,4 Basic
        // 5,6,7 Advanced
        // 8,9: Master
        // 10: Grand Master
        string *tough_level_desc = ({
                BLU "һ����֪" NOR,
                BLU "��������" NOR,
                BLU "����ҳ�" NOR,
                BLU "��ѧէ��" NOR,
                BLU "����ǿǿ" NOR,
                HIB "�����ž�" NOR,
                HIB "����é®" NOR,
                HIB "��֪һ��" NOR,
                HIB "����ͨͨ" NOR,
                HIB "ƽƽ����" NOR,
                CYN "ƽ������" NOR,
                CYN "��ͨƤë" NOR,
                CYN "��������" NOR,
                CYN "������" NOR,
                CYN "����С��" NOR,
                HIC "����С��" NOR,
                HIC "������Ⱥ" NOR,
                HIC "�������" NOR,
                HIC "�������" NOR,
                HIC "�ڻ��ͨ" NOR,
                HIG "�������" NOR,
                HIG "¯����" NOR,
                HIG "��Ȼ����" NOR,
                HIG "���д��" NOR,
                HIG "���д��" NOR,
                YEL "��Ȼ��ͨ" NOR,
                YEL "�������" NOR,
                YEL "�޿�ƥ��" NOR,
                YEL "����Ⱥ��" NOR,
                YEL "����似" NOR,
                HIY "�����뻯" NOR,
                HIY "��ͬ����" NOR,
                HIY "����Ⱥ��" NOR,
                HIY "�Ƿ��켫" NOR,
                HIY "�����ױ�" NOR,
                RED "��������" NOR,
                RED "һ����ʦ" NOR,
                RED "�������" NOR,
                RED "�񹦸���" NOR,
                RED "������˫" NOR,
                WHT "��������" NOR,
                WHT "���춯��" NOR,
                WHT "������" NOR,
                WHT "������ʥ" NOR,
                WHT "�������" NOR,
                HIW "��ǰ����" NOR,
                HIW "���˺�һ" NOR,
                MAG "��ز�¶" NOR,
                HIM "��ɲ�" NOR,
                HIR "��豹���" NOR
        });
        string desc;

        if( flag == 2 )
                level = max_talent_ability[arg];
        else
                level = max_ability[arg];
        if( !level ) level = 5;

        desc = sprintf(HIM"%3d/%3d"NOR, lev, level);
        if( lev >= 10 ) lev = 10;
        return (tough_level_desc[lev]+"��"+ desc+"��");
}

/*
�츳ϵ�޸� ���ã����������ϵ��
����ϵ
�������У����ͶԷ����������������Ķ������ʣ�
����ɱ¾�������Լ������������˺���
��ѪԪ�����еļ���,�ڻ��жԷ��������һ�ζ�������������
����ϵ
�����мܣ������Լ����������������мܼ��ʣ�
��Ʒ���ʣ�������������������������˺���
ͭǽ���ڣ����м���,�ڱ����к�Ե��˽���һ�α��е�������;
��ѧϵ
������ţ������ٷ�֮���Ķ����ѧϰЧ��
��ͯ�����������ٷ�֮������ϰ���о�Ч��
��ѧ��ţ����аٷ�֮������,�ڼ�������ʱ��ʹ���������;��������һ����
�ָ�ϵ
������ǣ��������˹����˹�Ч
������������������ս�����Զ�����Ч��
ǧ�����ˣ�ս���б����У��Զ��ָ�����Ѫ�Ĳ��� ���͸��඾�Է���ʱ�䡣
����ϵ
������գ�������ٷ�֮���Ķ����Ǯ������
��»������������ٷ�֮���Ķ��⾭�顢Ǳ�ܡ���ᣡ
���˴�ʦ��������ٷ�֮���Ķ���Ӣ�µ�����������Ϊ������ ��ʯ��Ŀ���������ˡ��Ϲ��ؾ��������Ե����ȡ��Ʒ��Ʒ��ͨ������ȵȵļ��ʸ���
*/
