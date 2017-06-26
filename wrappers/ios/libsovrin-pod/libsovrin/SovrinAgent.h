//
//  SovrinAgent.h
//  libsovrin
//


#import <Foundation/Foundation.h>
#import "SovrinTypes.h"

@interface SovrinAgent: NSObject

+ (NSError *)connectWithPoolHandle:(SovrinHandle)poolHandle
                      walletHandle:(SovrinHandle)walletHandle
                         senderDId:(NSString *)senderDid
                       receiverDId:(NSString *)receiverDid
                 connectionHandler:(void (^)(NSError *error, SovrinHandle connection)) connectionHandler
                    messageHandler:(void (^)(NSError *error, NSString *message)) messageHandler;

+ (NSError *)listenWithWalletHandle:(SovrinHandle)walletHandle
                           endpoint:(NSString *)endpoint
                    listenerHandler:(void (^)(NSError *error,
                                              SovrinHandle listenerHandle))listenerCompletion
                  connectionHandler:(void (^)(SovrinHandle xlistenerHandle,
                                              NSError *error,
                                              SovrinHandle connectionHandle,
                                              NSString *senderDid,
                                              NSString *receiverDid))connectionCompletion
                     messageHandler:(void (^)(SovrinHandle xconnectionHandle,
                                              NSError *error,
                                              NSString *message))messageCompletion;

+ (NSError *)sendWithConnectionHandle:(SovrinHandle)connectionHandle
                             messsage:(NSString *)message
                           completion:(void (^)(NSError *error)) handler;

+ (NSError *)closeConnection:(SovrinHandle)connectionHandle
                  completion:(void (^)(NSError *error)) handler;

+ (NSError *)closeListener:(SovrinHandle)listenerHandle
                completion:(void (^)(NSError *error)) handler;
@end
