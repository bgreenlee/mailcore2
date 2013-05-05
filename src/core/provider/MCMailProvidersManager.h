//
//  MCMailProvidersManager.h
//  mailcore2
//
//  Created by Robert Widmann on 4/28/13.
//  Copyright (c) 2013 MailCore. All rights reserved.
//

#ifndef __MAILCORE_MCMAILPROVIDERSMANAGER_H_
#define __MAILCORE_MCMAILPROVIDERSMANAGER_H_

#include <MailCore/MCBaseTypes.h>

#ifdef __cplusplus

namespace mailcore {
	class MailProvider;
	
	class MailProvidersManager : public Object {
        
	public:
		static MailProvidersManager * sharedManager();
		
		virtual MailProvider * providerForEmail(String * email);
		virtual MailProvider * providerForMX(String * hostname);
		virtual MailProvider * providerForIdentifier(String * identifier);
		
		virtual void registerProvidersWithFilename(String * filename);
		
	private:
		MailProvidersManager();
		void registerProviders(HashMap * providers);
		
		HashMap * mProviders;
		
		void init();
	};
}

#endif

#endif /* defined(__MAILCORE__MCMailProvidersManager__) */
