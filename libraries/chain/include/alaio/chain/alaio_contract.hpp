#pragma once

#include <alaio/chain/types.hpp>
#include <alaio/chain/contract_types.hpp>

namespace alaio { namespace chain {

   class apply_context;

   /**
    * @defgroup native_action_handlers Native Action Handlers
    */
   ///@{
   void apply_alaio_newaccount(apply_context&);
   void apply_alaio_updateauth(apply_context&);
   void apply_alaio_deleteauth(apply_context&);
   void apply_alaio_linkauth(apply_context&);
   void apply_alaio_unlinkauth(apply_context&);

   /*
   void apply_alaio_postrecovery(apply_context&);
   void apply_alaio_passrecovery(apply_context&);
   void apply_alaio_vetorecovery(apply_context&);
   */

   void apply_alaio_setcode(apply_context&);
   void apply_alaio_setabi(apply_context&);

   void apply_alaio_canceldelay(apply_context&);
   ///@}  end action handlers

} } /// namespace alaio::chain
