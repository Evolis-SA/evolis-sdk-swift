// swift-tools-version:5.4

import PackageDescription

let package = Package(
    name: "EvolisSDK",
    platforms: [
        .macOS(.v10_14), .iOS(.v14),
    ],
    products: [
        .library(
            name: "EvolisSDK",
            targets: ["EvolisSDK"]),
    ],
    targets: [
        .binaryTarget(
            name: "EvolisSDK",
            path: "EvolisSDK.xcframework"
        ),
    ]
)
