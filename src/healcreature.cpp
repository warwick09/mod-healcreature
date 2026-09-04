#include "Chat.h"
#include "CommandScript.h"
#include "Creature.h"
#include "ScriptMgr.h"
#include "Unit.h"

using namespace Acore::ChatCommands;

class healcreature_commandscript : public CommandScript
{
public:
    healcreature_commandscript()
        : CommandScript("healcreature_commandscript")
    {
    }

    ChatCommandTable GetCommands() const override
    {
        static ChatCommandTable commandTable =
        {
            { "healcreature", HandleHealCreatureCommand, rbac::RBAC_PERM_COMMAND_GM, Console::No }
        };

        return commandTable;
    }

    static bool HandleHealCreatureCommand(ChatHandler* handler)
    {
        Creature* target = handler->getSelectedCreature();

        if (!target)
        {
            handler->SendSysMessage("You must select a creature.");
            return false;
        }

        if (!target->IsAlive())
        {
            handler->SendSysMessage("That creature is dead.");
            return false;
        }

        uint32 missingHealth = target->GetMaxHealth() - target->GetHealth();

        if (missingHealth == 0)
        {
            handler->SendSysMessage("That creature is already at full health.");
            return false;
        }

        Unit::DealHeal(
            handler->GetSession()->GetPlayer(),
            target,
            missingHealth
        );

        handler->PSendSysMessage(
            "Healed {} for {}.",
            target->GetName(),
            missingHealth
        );

        return true;
    }
};

void AddSC_healcreature()
{
    new healcreature_commandscript();
}
