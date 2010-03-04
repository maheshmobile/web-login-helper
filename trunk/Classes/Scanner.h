#import <CoreFoundation/CoreFoundation.h>
#import <Foundation/NSTimer.h>
#import <Foundation/Foundation.h>
#include <dlfcn.h>
#include <ifaddrs.h>
#include <arpa/inet.h>

@interface MSNetworksManager : NSObject {
	
	NSMutableDictionary *networks;
	NSArray *types;
	int autoScanInterval;
	bool scanning;
	bool autoScanning;
	void *libHandle;
	void *airportHandle;
	
	int (*open)(void *);
	int (*bind)(void *, NSString *);
	int (*close)(void *);
	int (*associate)(void *, NSDictionary*, NSString*);
	int (*scan)(void *, NSArray **, void *);
	
	//int (*open)(void *);
	//int (*bind)(void *, NSString *);
	//int (*close)(void *);
	//int (*scan)(void *, NSArray **, void *);
	//int (*associate)(void*, NSDictionary *, NSString *);
	int (*getpower)(void *, char *);
	int (*setpower)(void*, char*);
}

+ (MSNetworksManager *)sharedNetworksManager;
+ (NSNumber *)numberFromBSSID:(NSString *) bssid;
- (NSDictionary *)networks;
- (NSDictionary *)networks:(int) type;
- (NSDictionary *)network:(NSString *) aNetwork;
- (id)init;
- (void)dealloc;
- (int)numberOfNetworks;
- (int)numberOfNetworks:(int) type;
- (int)autoScanInterval;
- (void)scan;
- (void)removeNetwork:(NSString *)aNetwork;
- (void)removeAllNetworks;
- (void)removeAllNetworks:(int) type;
- (void)autoScan:(bool)scan;
- (bool)autoScan;
- (void)scanSelector:(id)param;
- (void)setAutoScanInterval:(int) scanInterval;
- (int)associateNetwork: (NSDictionary *)bss: (NSString *)password;
- (int)getPower: (char *)power;
- (int)setPower: (char *)power;
- (NSString *) localIPAddress;

@end
